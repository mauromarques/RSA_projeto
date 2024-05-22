import numpy as np
#import matplotlib.pyplot as plt
#import matplotlib.colors as mcolors
import sys






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

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python test.y <sensor_data_file>")
        sys.exit(1)

    global selfCoordinates, listening_ip, otherCoordinates
    sensor_data_file = sys.argv[1]
    #listening_ip = sys.argv[2]
    range_radius = 15  # Radius of the range circle
    selfCoordinates = (0,0)
    otherCoordinates = []

    # Read sensor data
    sensor_data = read_sensor_data(sensor_data_file)
    print(sensor_data)
    # Plot heat map
    #fig, ax = plot_heat_map(sensor_data, "Heat Map")

