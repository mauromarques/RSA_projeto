#!/bin/bash

# Check if the number of applications to launch is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <number_of_apps>"
  exit 1
fi

# Number of applications to launch
num_apps=$1
GRID_DIMENSION=100

# Generate the identifiers
identifiers=()
for ((i = 0; i < num_apps; i++)); do
  identifiers+=($((20 + i * 10)))
done

# Launch each application in a new gnome-terminal tab
for ((i = 0; i < num_apps; i++)); do
  self_id=${identifiers[i]}
  randomX=$(shuf -i 0-$GRID_DIMENSION -n 1)
  randomY=$(shuf -i 0-$GRID_DIMENSION -n 1)
  params=("$self_id $randomX $randomY $GRID_DIMENSION")

  gnome-terminal --tab -- bash -c "python3 obu.py ${params[*]} ; exec bash"
done

