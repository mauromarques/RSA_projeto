import matplotlib.pyplot as plt

def plot_gps_paths(file_paths):
    colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k']  # List of colors for plotting

    plt.figure(figsize=(10, 6))

    for i, file_path in enumerate(file_paths):
        # Read coordinates from the file
        with open(file_path, 'r') as file:
            lines = file.readlines()

        # Extract latitude and longitude values
        latitudes = []
        longitudes = []
        for line in lines:
            lat, lon = map(float, line.strip().split(','))
            latitudes.append(lat)
            longitudes.append(lon)

        # Plot the path
        plt.plot(longitudes, latitudes, marker='o', linestyle='-', color=colors[i % len(colors)], label=f'Path {i+1}')

    plt.title('GPS Paths')
    plt.xlabel('Longitude')
    plt.ylabel('Latitude')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    num_files = int(input("Enter the number of GPS coordinate files: "))
    file_paths = []
    for i in range(num_files):
        file_path = input(f"Enter the path to GPS coordinates file {i+1}: ")
        file_paths.append(file_path)

    plot_gps_paths(file_paths)

