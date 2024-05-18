#!/bin/bash

# Define variables
OBU_TO_OBSERVE=20
NUM_HEAT_POINTS=5
GRID_DIMENSION=50
SENSOR_MAX_VALUE=100
SENSOR_VARIATION_RANGE=4

# Execute generateSensors.py script
echo "Executing generateSensors.py..."
python3 generateSensors.py $GRID_DIMENSION $SENSOR_MAX_VALUE $SENSOR_VARIATION_RANGE $NUM_HEAT_POINTS
echo "------------------------------------"

# Execute generateHeatMap.py script
echo "Executing generateHeatMap.py..."
python3 generateHeatMap.py sensor_data.txt $OBU_TO_OBSERVE
echo "------------------------------------"

echo "All scripts executed."
