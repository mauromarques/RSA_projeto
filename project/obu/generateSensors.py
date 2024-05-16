import random
import math
import sys
import os

# Function to generate sensor readings based on distance to the heat point
def generate_heat_map_readings(grid_size, base_value, variation_range):
    heat_point_x = random.randint(0, grid_size - 1)  # Generate random x coordinate for heat point
    heat_point_y = random.randint(0, grid_size - 1)  # Generate random y coordinate for heat point
    heat_point = (heat_point_x, heat_point_y)

    readings = []

    for x in range(grid_size):
        for y in range(grid_size):
            distance = math.sqrt((x - heat_point[0])**2 + (y - heat_point[1])**2)
            value = max(base_value - distance * variation_range, 0)
            value += random.uniform(-variation_range, variation_range)  # Add some noise
            readings.append((x, y, value))

    return readings, heat_point

# Check if the correct number of command-line arguments is provided
if len(sys.argv) != 4:
    print("Usage: python generate_sensor_data.py <grid_size> <base_value> <variation_range>")
    sys.exit(1)

try:
    grid_size = int(sys.argv[1])
    base_value = float(sys.argv[2])
    variation_range = float(sys.argv[3])
except ValueError:
    print("Arguments must be integers or floats.")
    sys.exit(1)

# Check if the files already exist and delete them
sensor_files = ['sensor_data.txt']
for file in sensor_files:
    if os.path.exists(file):
        os.remove(file)
        print(f"Existing file {file} deleted.")

# Generate sensor readings for each sensor type
sensor_readings, heat_point = generate_heat_map_readings(grid_size, base_value, variation_range)

# Write sensor readings to separate text files with coordinates
sensor_data = {
    'sensor_data.txt': sensor_readings,
}

for filename, readings in sensor_data.items():
    with open(filename, 'w') as file:
        for x, y, value in readings:
            file.write(f"{x},{y},{value}\n")

print(f"Heat map sensor readings generated with heat point at {heat_point}, base value of {base_value}, and variation range of {variation_range}. Data saved to file.")
