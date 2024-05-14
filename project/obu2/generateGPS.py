import random
import math
import sys
import os

# Coordinates for the University of Aveiro (approximate)
aveiro_lat = 40.6306
aveiro_lon = -8.6571

# Function to generate coordinates following a random walk
def generate_random_walk_coordinates(lat, lon, num_steps, step_distance):
    latitudes = [lat]
    longitudes = [lon]

    for _ in range(num_steps):
        # Generate random step direction (in radians)
        angle = random.uniform(0, 2 * math.pi)

        # Convert angle to latitude and longitude offsets
        lat_offset = step_distance * math.cos(angle) / 111000  # 1 degree of latitude is approximately 111000 meters
        lon_offset = step_distance * math.sin(angle) / (111000 * abs(math.cos(math.radians(lat))))  # Adjust longitude offset based on latitude

        # Calculate new latitude and longitude
        new_lat = latitudes[-1] + lat_offset
        new_lon = longitudes[-1] + lon_offset

        # Append new coordinates to the list
        latitudes.append(new_lat)
        longitudes.append(new_lon)

    return latitudes, longitudes

# Check if the correct number of command-line arguments is provided
if len(sys.argv) != 4:
    print("Usage: python generate_gps.py <num_steps> <step_distance> <radius>")
    sys.exit(1)

try:
    num_steps = int(sys.argv[1])
    step_distance = float(sys.argv[2])
    radius = float(sys.argv[3])
except ValueError:
    print("Number of steps, step distance, and radius must be integers or floats.")
    sys.exit(1)

# Check if the file already exists and delete it
if os.path.exists('gps_coordinates.txt'):
    os.remove('gps_coordinates.txt')
    print("Existing file gps_coordinates.txt deleted.")

# Generate coordinates
latitudes, longitudes = generate_random_walk_coordinates(aveiro_lat, aveiro_lon, num_steps, step_distance)

# Write coordinates to a text file
with open('gps_coordinates.txt', 'w') as file:
    for lat, lon in zip(latitudes, longitudes):
        file.write(f"{lat},{lon}\n")

print(f"{num_steps} coordinates generated following a random walk with a step distance of {step_distance} meters, and saved to gps_coordinates.txt.")

