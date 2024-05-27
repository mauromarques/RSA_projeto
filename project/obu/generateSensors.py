import random
import math
import sys
import os

# Function to generate sensor readings based on distance to the heat points
def generate_heat_map_readings(grid_size, base_value, variation_range, num_heat_points):
    heat_points = [(random.randint(0, grid_size), random.randint(0, grid_size)) for _ in range(num_heat_points)]

    readings = []

    for x in range(grid_size + 1):  # Adjusted range to include the maximum coordinate
        for y in range(grid_size + 1):  # Adjusted range to include the maximum coordinate
            distances = [math.sqrt((x - hx)**2 + (y - hy)**2) for hx, hy in heat_points]
            min_distance = min(distances)
            value = max(base_value - min_distance * variation_range, 0)
            #value += random.uniform(-variation_range, variation_range)  # Add some noise
            readings.append((x, y, value))

    return readings, heat_points

# Check if the correct number of command-line arguments is provided
if len(sys.argv) != 5:
    print("Usage: python generate_sensor_data.py <grid_size> <base_value> <variation_range> <num_heat_points>")
    sys.exit(1)

try:
    grid_size = int(sys.argv[1])
    base_value = float(sys.argv[2])
    variation_range = float(sys.argv[3])
    num_heat_points = int(sys.argv[4])
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
sensor_readings, heat_points = generate_heat_map_readings(grid_size, base_value, variation_range, num_heat_points)

# Write sensor readings to separate text files with coordinates
sensor_data = {
    'sensor_data.txt': sensor_readings,
}

for filename, readings in sensor_data.items():
    with open(filename, 'w') as file:
        for x, y, value in readings:
            file.write(f"{x},{y},{value}\n")

print(f"Heat map sensor readings generated with {num_heat_points} heat points, base value of {base_value}, and variation range of {variation_range}. Data saved to file.")
