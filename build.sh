#!/bin/bash

# Create the build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build

# Run cmake command
cmake ..

# Build the project
make

#creator package
cpack
