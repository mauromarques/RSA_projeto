import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.animation as animation
import sys
import json
import paho.mqtt.client as mqtt
import threading
from time import sleep

def on_connect(client, userdata, flags, rc, properties):
    print("Connected with result code " + str(rc))
    client.subscribe("simulation/location_update")

def on_message(client, userdata, msg):
    global selfCoordinates, listening_ip, otherCoordinates
    message = msg.payload.decode('utf-8')
    print('Topic: ' + msg.topic)
    #print('Message: ' + message + "\n")
    obj = json.loads(message)
    
    if msg.topic == "simulation/location_update":
        stationID = int(int(obj.get("stationID"))*10)
        lat = obj.get("latitude")
        lon = obj.get("longitude")
        print("Update location for OBU " + str(stationID))
        if int(listening_ip) == int(stationID):
            selfCoordinates = (lat, lon)
        else:
            # Flag to check if stationID exists in otherCoordinates
            exists = False
            # Iterate through otherCoordinates to find if stationID exists
            for entry in otherCoordinates:
                if entry[0] == stationID:
                    # Update lat and lon if stationID is found
                    entry[1] = lat
                    entry[2] = lon
                    exists = True
                    break
            # If stationID does not exist, append the new data
            if not exists:
                otherCoordinates.append([stationID, lat, lon])

def read_sensor_data(filename):
    coords = []
    values = []
    with open(filename, 'r') as file:
        for line in file:
            x, y, value = map(float, line.strip().split(','))
            coords.append((int(x), int(y)))
            values.append(value)
    
    # Infer grid size from max coordinates
    max_x = max(coord[0] for coord in coords) + 1
    max_y = max(coord[1] for coord in coords) + 1
    
    data = np.zeros((max_x, max_y))
    for (x, y), value in zip(coords, values):
        data[x, y] = value

    return data

def plot_heat_map(data, title):
    # Create a custom colormap
    cmap = mcolors.LinearSegmentedColormap.from_list('custom_cmap', ['green', 'yellow', 'red'])
    
    fig, ax = plt.subplots(figsize=(10, 10))
    cax = ax.imshow(data, cmap=cmap, interpolation='nearest')
    fig.colorbar(cax)
    ax.set_title(title)
    return fig, ax

def animate_floating_point(ax, range_radius):
    point, = ax.plot([], [], 'bo', markersize=10)  # Blue point
    circle = plt.Circle((0, 0), range_radius, color='b', fill=False)
    red_points, = ax.plot([], [], 'ro', markersize=5)  # Red points
    red_texts = []  # List to store text annotations

    def update(frame):
        global selfCoordinates, otherCoordinates
        x, y = selfCoordinates
        point.set_data(x, y)
        circle.center = (x, y)
        ax.add_patch(circle)  # Add the circle to the plot

        # Clear previous texts
        for text in red_texts:
            text.remove()
        red_texts.clear()

        if len(otherCoordinates) > 0:
            other_x, other_y = zip(*[coord[1:] for coord in otherCoordinates])
            red_points.set_data(other_x, other_y)

            for (stationID, ox, oy) in otherCoordinates:
                text = ax.text(ox, oy, str(stationID), color='red', fontsize=12, ha='center', va='bottom')
                red_texts.append(text)
        else:
            red_points.set_data([], [])
        
        return point, red_points, *red_texts

    ani = animation.FuncAnimation(ax.figure, update, frames=1, interval=0, blit=True)
    plt.show()

if len(sys.argv) != 3:
    print("Usage: python plot_heat_map_with_animation.py <sensor_data_file> <listening_ip>")
    sys.exit(1)

global selfCoordinates, listening_ip, otherCoordinates
sensor_data_file = sys.argv[1]
listening_ip = sys.argv[2]
range_radius = 15  # Radius of the range circle
selfCoordinates = (0,0)
otherCoordinates = []

# Read sensor data
sensor_data = read_sensor_data(sensor_data_file)

# Plot heat map
fig, ax = plot_heat_map(sensor_data, "Heat Map")

# Base IP address
baseIP = "192.168.98."

# Create the client for listening to messages
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.on_connect = on_connect
client.connect(baseIP + listening_ip, 1883, 60)
client.on_message = on_message

# Start the MQTT client in a separate thread
threading.Thread(target=client.loop_forever).start()

# Animate floating point with a range circle around it
animate_floating_point(ax, range_radius)
