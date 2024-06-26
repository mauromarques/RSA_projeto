import json
import paho.mqtt.client as mqtt
import threading
from time import sleep
import sys
import math
import random
import datetime
import heapq
from enum import Enum

# Node states
class NodeAction(Enum):
    STATIONED = "stationed"
    MOVING_TOWARDS_SAFETY = "moving towards safe spot"
    SEARCHING_FOR_SAFETY = "searching for safety"
    MOVING_OUT_OF_DANGER = "in danger, following a lead"

# Global variables
action = NodeAction.SEARCHING_FOR_SAFETY
objective = None
currentPosition = (0, 0)
full_sensor_data = {}
sensor_values = {}
sensorMap = {}
station_locations = {}
listening_ip = ""
clients = []
connected_ips = set()
baseIP = "192.168.98."
table_data = [
    {"number": i, "last_update_time": "--", "status": "MISSING", "gps_location": "--", "action": "--"}
    for i in range(2, 7)
]

def update_table():
    current_time = datetime.datetime.now()
    for row in table_data:
        station_id = row["number"]
        if station_id in station_locations and row["status"] == "CONNECTED":
            latitude, longitude = station_locations[station_id]
            row["gps_location"] = f"{latitude:.4f}, {longitude:.4f}"
            row_update_time = row["last_update_time"]
            if row_update_time != "--":
                row_update_time = datetime.datetime.strptime(row_update_time, "%Y-%m-%d %H:%M:%S")
                time_difference = (current_time - row_update_time).total_seconds()
                if time_difference > 10:
                    row["status"] = "MISSING"

def print_table():
    print(f"OBSERVING OBU: 2\n{'No':<5} {'Last Update Time':<20} {'Status':<10} {'GPS Location':<20} {'Action'}")
    print("-" * 80)
    for row in table_data:
        print(f"{row['number']:<5} {row['last_update_time']:<20} {row['status']:<10} {row['gps_location']:<20} {row['action']}")

def update_table_status(station_id, status, update_time=None, action=None):
    for row in table_data:
        if row["number"] == station_id:
            row["status"] = status
            if update_time:
                row["last_update_time"] = update_time
            if action:
                row["action"] = action
            break

def on_connect(client, userdata, flags, rc, properties=None):
    client.subscribe("vanetza/out/cam")
    client.subscribe("sensors/evaluation")
    client.subscribe("report/action")

def on_message(client, userdata, msg):
    global sensor_values, station_locations, currentPosition
    message = msg.payload.decode('utf-8')
    obj = json.loads(message)

    station_id = obj.get("stationID")
    latitude = obj.get("latitude")
    longitude = obj.get("longitude")

    if station_id is not None and latitude is not None and longitude is not None:
        station_locations[station_id] = (latitude, longitude)

    connected_nodes = find_connected_nodes(int(int(listening_ip) / 10), station_locations, 70)

    if station_id not in connected_nodes:
        update_table_status(station_id, "MISSING")
        return
    
    update_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    update_table_status(station_id, "CONNECTED", update_time)

    if msg.topic == "vanetza/out/cam":
        sender_ip = str(obj.get("stationID")*10)
        if sender_ip and sender_ip not in connected_ips:
            connect_client(sender_ip)
        client.publish("simulation/location_update", json.dumps(obj))

    if msg.topic == "sensors/evaluation":
        for value in obj.get("values", []):
            x = value.get("x")
            y = value.get("y")
            if x is not None and y is not None and value.get("value") is not None:
                sensor_values[(x, y)] = value.get("value")

    if msg.topic == "report/action":
        action = obj.get("values", [])
        update_table_status(station_id, "CONNECTED", update_time, action=action)

def connect_client(ip):
    global baseIP, clients, connected_ips
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.connect(baseIP + ip, 1883, 60)
    clients.append(client)
    connected_ips.add(ip)

def a_star_search(mapa, start, goal):
    def heuristic(a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])
    
    def get_neighbors(position):
        x, y = position
        neighbors = [
            (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1),
            (x + 1, y + 1), (x - 1, y + 1), (x + 1, y - 1), (x - 1, y - 1)
        ]
        # Filter out neighbors that are out of bounds or unsafe
        #neighbors = [(nx, ny) for nx, ny in neighbors if 0 <= nx < len(map) and 0 <= ny < len(map[0]) and map[nx][ny] == 0]
        return neighbors
    
    open_set = []
    heapq.heappush(open_set, (0, start))
    came_from = {}
    cost_so_far = {start: 0}

    while open_set:
        current_priority, current = heapq.heappop(open_set)

        if current == goal:
            break

        for neighbor in get_neighbors(current):
            #neighbor = (current[0] + dx, current[1] + dy)
            if neighbor in mapa:
                new_cost = cost_so_far[current] + mapa[neighbor]
                if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                    cost_so_far[neighbor] = new_cost
                    priority = new_cost + heuristic(goal, neighbor)
                    heapq.heappush(open_set, (priority, neighbor))
                    came_from[neighbor] = current

    # Reconstruir o caminho a partir do 'goal' até 'start'
    path = []
    if goal in came_from:
        current = goal
        while current != start:
            path.append(current)
            current = came_from[current]
        path.append(start)
        path.reverse()

    return path

def get_lowest_reading_in_radius(sensorMap, current_location, radius=5):
    current_x, current_y = current_location
    lowest_reading = float('inf')
    lowest_coordinates = None

    for (x, y), reading in sensorMap.items():
        # Calculate the distance from the current location
        distance = math.sqrt((x - current_x)**2 + (y - current_y)**2)
        
        # Check if the distance is within the specified radius
        if distance <= radius:
            # Check if this reading is the lowest we've found
            if reading < lowest_reading:
                lowest_reading = reading
                lowest_coordinates = (x, y)
    
    return lowest_coordinates

def next_step(current_position, mapa):
    global objective, action, sensorMap
    #print("next step action: " + str(action))
    if action == NodeAction.MOVING_TOWARDS_SAFETY or action == NodeAction.MOVING_OUT_OF_DANGER: # Node has a better objective and is trying to reach it
        path = a_star_search(mapa, current_position, objective)
        if path:
            return path[1]  # Retorna o próximo passo na rota   
        else:
            return current_position
    if action == NodeAction.SEARCHING_FOR_SAFETY: # Node has no better objective and is looking by itself
        nextPlaceToExplore = get_lowest_reading_in_radius(sensorMap, current_position)
        path = a_star_search(mapa, current_position, nextPlaceToExplore)
        if path:
            return path[1]  # Retorna o próximo passo na rota   
        else:
            return current_position
    if action == NodeAction.STATIONED: # Node has reached safety
        return current_position
    
        
def find_lowest_value_position():
    global sensor_values
    if not sensor_values:
        return None
    lowest_key = min(sensor_values, key=sensor_values.get)
    lowest_value = sensor_values[lowest_key]
    return (lowest_key, lowest_value)


def read_sensor_data():
    global full_sensor_data
    full_sensor_data = {}
    with open('sensor_data.txt', 'r') as f:
        for line in f:
            x, y, value = map(float, line.strip().split(','))
            full_sensor_data[(x, y)] = value

def update_sensor_values_within_radius():
    global sensor_values, currentPosition, sensorMap, full_sensor_data
    values_for_calculation = {}
    total_value = 0
    count = 0
    for (x, y), value in full_sensor_data.items():
        distance = math.sqrt((currentPosition[0] - x)**2 + (currentPosition[1] - y)**2)
        if distance <= 5:
            values_for_calculation[(x, y)] = value
            sensorMap[(x, y)] = value
            total_value += value
            count += 1
        else:
            sensorMap[(x, y)] = 404
    if count > 0:
        average_value = total_value / count
        sensor_values[currentPosition] = average_value

def find_connected_nodes(current_position, station_locations, radius):
    visited = set()
    queue = [current_position]
    connected_nodes = []

    while queue:
        node = queue.pop(0)
        if node not in visited:
            visited.add(node)
            connected_nodes.append(node)

            for other_node in station_locations.keys():
                if other_node != node and other_node not in visited:
                    node_coords = station_locations[node]
                    other_node_coords = station_locations[other_node]
                    distance = math.sqrt((node_coords[0] - other_node_coords[0])**2 + (node_coords[1] - other_node_coords[1])**2)
                    if distance <= radius:
                        queue.append(other_node)

    return connected_nodes

def generateCam():
    global currentPosition, sensor_values, objective
    update_sensor_values_within_radius()

    lat, lon = next_step(currentPosition,sensorMap)
    station_locations[int(int(listening_ip)/10)] = (lat, lon)

    currentPosition = (lat, lon)
    with open('in_cam.json', 'r') as f:
        m = json.load(f)
    m["latitude"] = lat
    m["longitude"] = lon
    m["stationID"] = int(int(listening_ip) / 10)
    print(json.dumps(m))
    client.publish("vanetza/in/cam", json.dumps(m))
    client.publish("simulation/location_update", json.dumps(m))

def generateLocationEvaluation():
    global currentPosition
    global listening_ip
    global clients
    global sensor_values

    with open('sensors_evaluation.json', 'r') as f:
        m = json.load(f)
    m["stationID"] = int(int(listening_ip) / 10)
    m["latitude"], m["longitude"] = currentPosition
    m["values"] = []

    for (x, y), value in sensor_values.items():
        m["values"].append({"x": x, "y": y, "value": value})

    for client in clients:
        client.publish("sensors/evaluation", json.dumps(m))

def generateActionReport():
    global currentPosition
    global listening_ip
    global clients
    global sensor_values
    global action

    with open('sensors_evaluation.json', 'r') as f:
        m = json.load(f)
    m["stationID"] = int(int(listening_ip) / 10)
    m["latitude"], m["longitude"] = currentPosition
    m["values"] = action.value

    for client in clients:
        client.publish("report/action", json.dumps(m))

def send_locationEvaluation():
    while True:
        print("evaluation")
        generateLocationEvaluation()
        sleep(1)

def send_cam():
    while True:
        print("cam")
        generateCam()
        sleep(1)

def send_actionReport():
    while True:
        print("action report")
        generateActionReport()
        sleep(2)

def print_table_periodically():
    while True:
        print("table")
        update_table()
        print("\033[H\033[J", end="")  # Clear screen
        print_table()
        sleep(1)

def updateAction():
    while True:
        print("action")
        newAction()
        sleep(0.5)

def newAction():
    global action, currentPosition, sensor_values, objective
    update_sensor_values_within_radius()
    safestPlaceKnown, safestPlaceEvaluation = find_lowest_value_position()
    # FOUND SAFE SPOT, IS NOT AT SAFE SPOT -> move there
    if safestPlaceEvaluation <= 29 and safestPlaceKnown != currentPosition:
        action = NodeAction.MOVING_TOWARDS_SAFETY
        objective = safestPlaceKnown
    # FOUND SAFE SPOT, IS AT SAFE SPOT -> stay still
    elif safestPlaceEvaluation <= 29 and safestPlaceKnown == currentPosition:
        action = NodeAction.STATIONED
    # FOUND MEDIUM SAFE SPOT, IS AT DANGEROUS SPOT -> move there
    elif safestPlaceEvaluation >= 30 and safestPlaceEvaluation <= 49 and sensor_values[currentPosition] >= 50:
        action = NodeAction.MOVING_OUT_OF_DANGER
        objective = safestPlaceKnown
    # NOT FOUND SAFE SPOT -> search for better spot
    else:
        action = NodeAction.SEARCHING_FOR_SAFETY

# Command-line argument
listening_ip = sys.argv[1]
currentPosition = (int(sys.argv[2]), int(sys.argv[3]))

# Stores all sensor readings
read_sensor_data()

# Create the client for listening to messages
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.on_connect = on_connect
client.connect(baseIP + listening_ip, 1883, 60)
client.on_message = on_message
clients.append(client)

# Add self IP to connected IPs
connected_ips.add(listening_ip)

# Start the MQTT client in a separate thread
threading.Thread(target=client.loop_forever).start()

# Start the threads for sending periodic messages
threading.Thread(target=send_cam).start()
threading.Thread(target=send_locationEvaluation).start()
threading.Thread(target=send_actionReport).start()
threading.Thread(target=updateAction).start()

# Start the thread for printing the table periodically
# threading.Thread(target=print_table_periodically).start()
