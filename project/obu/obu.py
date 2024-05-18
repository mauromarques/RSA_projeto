import json
import paho.mqtt.client as mqtt
import threading
from time import sleep
import sys

def on_connect(client, userdata, flags, rc, properties):
    print("Connected with result code " + str(rc))
    client.subscribe("vanetza/out/cam")
    client.subscribe("sensors/evaluation")

def on_message(client, userdata, msg):
    message = msg.payload.decode('utf-8')
    print('Topic: ' + msg.topic)
    #print('Message: ' + message + "\n")
    obj = json.loads(message)
    
    if msg.topic == "vanetza/out/cam":
        sender_ip = str(obj.get("stationID")*10)
        if sender_ip and sender_ip not in connected_ips:
            connect_client(sender_ip)
        client.publish("simulation/location_update", json.dumps(obj))
        

def connect_client(ip):
    global baseIP, clients, connected_ips
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.connect(baseIP + ip, 1883, 60)
    clients.append(client)
    connected_ips.add(ip)
    print(f"Connected to new client: {baseIP}{ip}")

def generateCam():
    obuNum = str(int(int(listening_ip) / 10))
    txtFileName = "gps_obu" + obuNum + ".txt"
    with open(txtFileName, 'r') as file:
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
    m["stationID"] = int(int(listening_ip)/10)
    client.publish("vanetza/in/cam", json.dumps(m))
    client.publish("simulation/location_update", json.dumps(m))

def generateLocationEvaluation():
    with open('sensors_evaluation.json', 'r') as f:
        m = json.load(f)
    m["stationID"] = int(listening_ip) / 10
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

# Command-line argument for self IP address
listening_ip = sys.argv[1]

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
