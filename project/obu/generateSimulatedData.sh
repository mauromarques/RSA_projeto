#!/bin/bash

# Check if the number of applications to launch is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <number_of_obus>"
  exit 1
fi

# Define variables
OBU_TO_OBSERVE=20
NUM_SAMPLES=500
NUM_OBUS=$1
GRID_DIMENSION=50
SENSOR_MAX_VALUE=100
SENSOR_VARIATION_RANGE=2

# Execute generateGPS.py script
echo "Executing generateGPS.py..."
python3 generateGPS.py $NUM_SAMPLES $GRID_DIMENSION $NUM_OBUS
echo "------------------------------------"

# Execute generateSensors.py script
echo "Executing generateSensors.py..."
python3 generateSensors.py $GRID_DIMENSION $SENSOR_MAX_VALUE $SENSOR_VARIATION_RANGE
echo "------------------------------------"

# Execute generateHeatMap.py script
echo "Executing generateHeatMap.py..."
python3 generateHeatMap.py sensor_data.txt $OBU_TO_OBSERVE
echo "------------------------------------"

echo "All scripts executed."
