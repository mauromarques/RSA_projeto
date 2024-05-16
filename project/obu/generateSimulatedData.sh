#!/bin/bash

# Define variables
NUM_SAMPLES=500
GRID_DIMENSION=50
SENSOR_MAX_VALUE=100
SENSOR_VARIATION_RANGE=2

# Execute generateGPS.py script
echo "Executing generateGPS.py..."
python3 generateGPS.py $NUM_SAMPLES $GRID_DIMENSION
echo "------------------------------------"

# Execute generateSensors.py script
echo "Executing generateSensors.py..."
python3 generateSensors.py $GRID_DIMENSION $SENSOR_MAX_VALUE $SENSOR_VARIATION_RANGE
echo "------------------------------------"

# Execute generateHeatMap.py script
echo "Executing generateHeatMap.py..."
python3 generateHeatMap.py sensor_data.txt gps_coordinates.txt
echo "------------------------------------"

echo "All scripts executed."
