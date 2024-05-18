import json
import paho.mqtt.client as mqtt
import threading
from time import sleep
import sys
import math
import random

def on_connect(client, userdata, flags, rc, properties):
    print("Connected with result code " + str(rc))
    client.subscribe("vanetza/out/cam")
    client.subscribe("sensors/evaluation")

def on_message(client, userdata, msg):
    global sensor_values
    message = msg.payload.decode('utf-8')
    #print('Topic: ' + msg.topic)
    #print('Message: ' + message + "\n")
    obj = json.loads(message)
    
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
        

def connect_client(ip):
    global baseIP, clients, connected_ips
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.connect(baseIP + ip, 1883, 60)
    clients.append(client)
    connected_ips.add(ip)
    print(f"Connected to new client: {baseIP}{ip}")


def next_step(current_position, objective=None):
    x, y = current_position

    # Define all possible moves including diagonals
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
        
        # Calculate Manhattan distance to objective for each move
        def distance(move):
            return abs(move[0] - obj_x) + abs(move[1] - obj_y)

        # Filter moves that are closer to the objective
        closer_moves = [move for move in possible_moves if distance(move) < distance(current_position)]

        if closer_moves:
            # Choose the move among the closer moves that minimizes the distance
            next_move = min(closer_moves, key=lambda move: distance(move))
        else:
            # If no closer moves are available, fall back to the move that minimizes the distance overall
            next_move = min(possible_moves, key=lambda move: distance(move))
    else:
        # If no objective, choose a random move
        next_move = random.choice(possible_moves)

    return next_move

def find_lowest_value_position():
    global sensor_values
    if not sensor_values:
        return None
    # Find the (x, y) position with the lowest sensor value
    return min(sensor_values, key=sensor_values.get)
    
def update_sensor_values_within_radius():
    global sensor_values, currentPosition
    values_for_calculation = {}
    total_value = 0
    count = 0

    with open('sensor_data.txt', 'r') as f:
        for line in f:
            x, y, value = map(float, line.strip().split(','))
            distance = math.sqrt((currentPosition[0] - x)**2 + (currentPosition[1] - y)**2)
            if distance <= 5:
                values_for_calculation[(x, y)] = value
                total_value += value
                count += 1
    # Calculate the average value
    if count > 0:
        average_value = total_value / count
        sensor_values[currentPosition] = average_value
    print("LULU")
    print(sensor_values[currentPosition])

def generateCam():
    global currentPosition, sensor_values
    update_sensor_values_within_radius()
    objective = find_lowest_value_position()
    
    lat, lon = next_step(currentPosition, objective)
    currentPosition = (lat, lon)
    with open('in_cam.json', 'r') as f:
        m = json.load(f)
    m["latitude"] = lat
    m["longitude"] = lon
    m["stationID"] = int(int(listening_ip)/10)
    client.publish("vanetza/in/cam", json.dumps(m))
    client.publish("simulation/location_update", json.dumps(m))
  
    try:
        print(objective)
        print(sensor_values[objective])
    except:
        pass

def generateLocationEvaluation():
    global currentPosition
    global listening_ip
    global clients
    global sensor_values

    # Initialize the message
    with open('sensors_evaluation.json', 'r') as f:
        m = json.load(f)
    m["stationID"] = int(listening_ip) / 10
    m["latitude"], m["longitude"] = currentPosition
    m["values"] = []

    # Add all sensor values to the message
    for (x, y), value in sensor_values.items():
        m["values"].append({"x": x, "y": y, "value": value})

    # Publish the message to all clients
    for client in clients:
        client.publish("sensors/evaluation", json.dumps(m))

def send_locationEvaluation():
    while True:
        generateLocationEvaluation()
        sleep(1)

def send_cam():
    while True:
        generateCam()
        sleep(1)

# Command-line argument
global currentPosition, sensor_values
sensor_values = {}
listening_ip = sys.argv[1]
currentPosition = (int(sys.argv[2]), int(sys.argv[3]))

# Array to hold MQTT clients
clients = []

# Set to keep track of connected IPs
connected_ips = set()

# Base IP address
baseIP = "192.168.98."

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
