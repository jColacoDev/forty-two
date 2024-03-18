#!/bin/bash

# Define min and max values for map dimensions and density
MIN_DIMENSION=9
MAX_DIMENSION=10
MIN_DENSITY=4
MAX_DENSITY=12
NUM_MAPS=5

# Function to generate a random number within a range
random_number() {
    echo $(($1 + RANDOM % ($2 - $1 + 1)))
}

# Loop to generate maps
for ((i=1; i<=$NUM_MAPS; i++)); do
    # Generate random dimensions and density
    x=$(random_number $MIN_DIMENSION $MAX_DIMENSION)
    y=$(random_number $MIN_DIMENSION $MAX_DIMENSION)
    density=$(random_number $MIN_DENSITY $MAX_DENSITY)

    # Print the arguments being passed to the Perl script
    echo "Generating map with dimensions: $x x $y, density: $density"

    # Generate map file using Perl script
    map_data=$(perl map_generator.pl $x $y $density)

    # Write map data to file
    echo "$map_data" > ./../maps/map_$i.txt
done

# Run BSQ program on each generated map
for ((i=1; i<=$NUM_MAPS; i++)); do
    ./../bsq ./../maps/map_$i.txt
done
