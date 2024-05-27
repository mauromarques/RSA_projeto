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
    MOVING_TOWARDS_SAFETY = "moving towards safety"
    STUCK = "stuck"
    SEARCHING_FOR_SAFETY = "searching for safety"
    SEARCHING_FOR_NODE = "searching for node"
    SEARCHING_BLIND = "searching blindly for a safe spot"

# Global variables
action = NodeAction.SEARCHING_BLIND
currentPosition = (0, 0)
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

    connected_nodes = find_connected_nodes(int(int(listening_ip) / 10), station_locations, 15)

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
    
    """"
    open_set = []
    heapq.heappush(open_set, (0, start))

    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}

    while open_set:
        _, current = heapq.heappop(open_set)

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.reverse()
            return path

        for neighbor in get_neighbors(current):
            tentative_g_score = g_score[current] + mapa[neighbor[0]][neighbor[1]]
            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = tentative_g_score + heuristic(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))

    return []  # Retorna uma lista vazia se não houver caminho
    """



def next_step(current_position, objective, mapa):
    path = a_star_search(mapa, current_position, objective)

    if path:
        return path[1]  # Retorna o próximo passo na rota   
    else:
        return current_position
        
"""
    

def next_step(current_position, objective=None,mapa = None):
    x, y = current_position
    possible_moves = [
        (x + 1, y),     # Right
        (x - 1, y),     # Left
        (x, y + 1),     # Up
        (x, y - 1),     # Down
        (x + 1, y + 1), # Up-right
        (x - 1, y + 1), # Up-left
        (x + 1, y - 1), # Down-right
        (x - 1, y - 1)  # Down-left
    ]

    if objective:
        obj_x, obj_y = objective

        def distance(move):
            return abs(move[0] - obj_x) + abs(move[1] - obj_y)

        closer_moves = [move for move in possible_moves if distance(move) < distance(current_position)]

        if closer_moves:
            next_move = min(closer_moves, key=lambda move: distance(move))
        else:
            next_move = min(possible_moves, key=lambda move: distance(move))
    else:
        next_move = random.choice(possible_moves)

    return next_move
"""

def find_lowest_value_position():
    global sensor_values
    if not sensor_values:
        return None
    return min(sensor_values, key=sensor_values.get)

def update_sensor_values_within_radius():
    global sensor_values, currentPosition, sensorMap
    values_for_calculation = {}
    total_value = 0
    count = 0

    with open('sensor_data.txt', 'r') as f:
        for line in f:
            x, y, value = map(float, line.strip().split(','))
            distance = math.sqrt((currentPosition[0] - x)**2 + (currentPosition[1] - y)**2)
            
            if distance <= 5:
                values_for_calculation[(x, y)] = value
                sensorMap[(x,y)] = value
                total_value += value
                count += 1
            else:
                sensorMap[(x,y)] = 404


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
    global currentPosition, sensor_values
    update_sensor_values_within_radius()
    objective = find_lowest_value_position()

    lat, lon = next_step(currentPosition, objective,sensorMap)
    station_locations[int(int(listening_ip)/10)] = (lat, lon)

    currentPosition = (lat, lon)
    with open('in_cam.json', 'r') as f:
        m = json.load(f)
    m["latitude"] = lat
    m["longitude"] = lon
    m["stationID"] = int(int(listening_ip) / 10)
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
        generateLocationEvaluation()
        sleep(1)

def send_cam():
    while True:
        generateCam()
        sleep(1)

def send_actionReport():
    while True:
        generateActionReport()
        sleep(2)

def print_table_periodically():
    while True:
        update_table()
        print("\033[H\033[J", end="")  # Clear screen
        print_table()
        sleep(1)

# Command-line argument
listening_ip = sys.argv[1]
currentPosition = (int(sys.argv[2]), int(sys.argv[3]))

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

# Start the thread for printing the table periodically
threading.Thread(target=print_table_periodically).start()
