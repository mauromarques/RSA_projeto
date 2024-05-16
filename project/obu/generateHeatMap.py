import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.animation as animation
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

def plot_heat_map(data, title):
    # Create a custom colormap
    cmap = mcolors.LinearSegmentedColormap.from_list('custom_cmap', ['green', 'yellow', 'red'])
    
    fig, ax = plt.subplots(figsize=(10, 10))
    cax = ax.imshow(data, cmap=cmap, interpolation='nearest')
    fig.colorbar(cax)
    ax.set_title(title)
    return fig, ax

def animate_floating_point(ax, coordinates_file, range_radius):
    coordinates = []

    with open(coordinates_file, 'r') as file:
        for line in file:
            x, y = map(int, line.strip().split(','))
            coordinates.append((x, y))

    point, = ax.plot([], [], 'bo', markersize=10)  # Blue point
    circle = plt.Circle((0, 0), range_radius, color='b', fill=False)

    def update(frame):
        x, y = coordinates[frame]
        point.set_data(x, y)
        circle.center = (x, y)
        ax.add_patch(circle)  # Add the circle to the plot
        return point,

    ani = animation.FuncAnimation(ax.figure, update, frames=len(coordinates), interval=10, blit=True)
    plt.show()

if len(sys.argv) != 3:
    print("Usage: python plot_heat_map_with_animation.py <sensor_data_file> <coordinates_file>")
    sys.exit(1)

sensor_data_file = sys.argv[1]
coordinates_file = sys.argv[2]
range_radius = 15  # Radius of the range circle

# Read sensor data
sensor_data = read_sensor_data(sensor_data_file)

# Plot heat map
fig, ax = plot_heat_map(sensor_data, "Heat Map")

# Animate floating point with a range circle around it
animate_floating_point(ax, coordinates_file, range_radius)
