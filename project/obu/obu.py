import json
import paho.mqtt.client as mqtt
import threading
from time import sleep
import sys

def on_connect(client, userdata, flags, rc, properties):
    print("Connected with result code "+str(rc))
    client.subscribe("vanetza/out/cam")
    client.subscribe("sensors/evaluation")

def on_message(client, userdata, msg):
    message = msg.payload.decode('utf-8')
    print('Topic: ' + msg.topic)
    print('Message: ' + message + "\n")
    obj = json.loads(message)
    # Process the received message if needed...

def generateCam():
    with open('gps_coordinates.txt', 'r') as file:
        try:
            position = int(open('position.txt').read())
        except FileNotFoundError:
            position = 0
        for _ in range(position):
            file.readline()
        line = file.readline().strip().split(',')
        lat, lon = float(line[0]), float(line[1])
        open('position.txt', 'w').write(str(position + 1))

    with open('in_cam.json', 'r') as f:
        m = json.load(f)
    m["latitude"] = lat
    m["longitude"] = lon
    client.publish("vanetza/in/cam", json.dumps(m))
    
def generateLocationEvaluation():
    # Replace for sensor data and evaluation of safety

    # Replace for evaluation model message
    with open('sensors_evaluation.json', 'r') as f:
        m = json.load(f)
    m["stationID"] = int(listening_ip)/10
    m["latitude"] = 0
    m["longitude"] = 0
    for client in clients:
        client.publish("sensors/evaluation", json.dumps(m))

def send_locationEvaluation():
    while True:
        generateLocationEvaluation()
        sleep(10)

def send_cam():
    while True:
        generateCam()
        sleep(1)

open('position.txt', 'w').write(str(0))

# Command-line arguments
ip_addresses = sys.argv[1:]  # Get all command-line arguments except the script name

# Separate the IP address for listening to messages
listening_ip = ip_addresses.pop(0)

# Array to hold MQTT clients
clients = []

# Base ip address
baseIP = "192.168.98."

# Iterate over the IP addresses and create clients
for ip in ip_addresses:
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.connect(baseIP+ip, 1883, 60)
    clients.append(client)

# Create the client for listening to messages
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.on_connect = on_connect
client.connect(baseIP+listening_ip, 1883, 60)
client.on_message = on_message
clients.append(client)

# Start the MQTT client in a separate thread
threading.Thread(target=client.loop_forever).start()

# Start the threads for sending periodic messages
threading.Thread(target=send_cam).start()
threading.Thread(target=send_locationEvaluation).start()

