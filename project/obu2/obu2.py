import json
import paho.mqtt.client as mqtt
import threading
from time import sleep

def on_connect(client, userdata, flags, rc, properties):
    print("Connected with result code "+str(rc))
    client.subscribe("vanetza/out/cam")

def on_message(client, userdata, msg):
    message = msg.payload.decode('utf-8')
    print('Topic: ' + msg.topic)
    print('Message: ' + message)
    obj = json.loads(message)
    # Process the received message if needed...

def generate():
    # Read coordinates from the file
    with open('gps_coordinates.txt', 'r') as file:
        # Read the last stored position from a file
        try:
            position = int(open('position.txt').read())
        except FileNotFoundError:
            position = 0

        # Move to the stored position in the file
        for _ in range(position):
            file.readline()

        # Read the next coordinate
        line = file.readline().strip().split(',')
        lat, lon = float(line[0]), float(line[1])

        # Store the next position
        open('position.txt', 'w').write(str(position + 1))

    # Read the template JSON message
    with open('in_cam.json', 'r') as f:
        m = json.load(f)

    # Update latitude and longitude in the message
    m["latitude"] = lat
    m["longitude"] = lon

    # Publish the message
    client.publish("vanetza/in/cam", json.dumps(m))
    print("Published message:", m)

    # Wait for a while before sending the next message
    sleep(1)

# MQTT setup
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.98.20", 1883, 60)

# Start the MQTT client in a separate thread
threading.Thread(target=client.loop_forever).start()

# Periodically generate and publish coordinates
while True:
    generate()

