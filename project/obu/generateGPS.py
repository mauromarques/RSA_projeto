import random
import sys
import os

# Function to generate coordinates following a random walk on a squared grid
def generate_random_walk_coordinates(num_steps, grid_dimension):
    start_x = random.randint(0, grid_dimension - 1)  # Random starting x coordinate within the grid
    start_y = random.randint(0, grid_dimension - 1)  # Random starting y coordinate within the grid
    x_positions = [start_x]
    y_positions = [start_y]

    for _ in range(num_steps):
        # Generate random step direction
        direction = random.choice(['up', 'down', 'left', 'right'])

        # Calculate new x and y positions based on the direction
        if direction == 'up' and y_positions[-1] < grid_dimension - 1:
            new_y = y_positions[-1] + 1
            new_x = x_positions[-1]
        elif direction == 'down' and y_positions[-1] > 0:
            new_y = y_positions[-1] - 1
            new_x = x_positions[-1]
        elif direction == 'left' and x_positions[-1] > 0:
            new_y = y_positions[-1]
            new_x = x_positions[-1] - 1
        elif direction == 'right' and x_positions[-1] < grid_dimension - 1:
            new_y = y_positions[-1]
            new_x = x_positions[-1] + 1
        else:
            # If the move is not valid (out of bounds), stay in the same place
            new_x = x_positions[-1]
            new_y = y_positions[-1]

        x_positions.append(new_x)
        y_positions.append(new_y)

    return x_positions, y_positions

# Check if the correct number of command-line arguments is provided
if len(sys.argv) != 3:
    print("Usage: python generate_gps.py <num_steps> <grid_dimension>")
    sys.exit(1)

try:
    num_steps = int(sys.argv[1])
    grid_dimension = int(sys.argv[2])
except ValueError:
    print("Number of steps and grid dimension must be integers.")
    sys.exit(1)

# Check if the file already exists and delete it
if os.path.exists('gps_coordinates.txt'):
    os.remove('gps_coordinates.txt')
    print("Existing file gps_coordinates.txt deleted.")

# Generate coordinates
x_positions, y_positions = generate_random_walk_coordinates(num_steps, grid_dimension)

# Write coordinates to a text file
with open('gps_coordinates.txt', 'w') as file:
    for x, y in zip(x_positions, y_positions):
        file.write(f"{x},{y}\n")

print(f"{num_steps} coordinates generated following a random walk on a {grid_dimension}x{grid_dimension} grid, and saved to gps_coordinates.txt.")
