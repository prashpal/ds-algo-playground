#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR="build"

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR"

# Run cmake, make, and ctest
echo "Running cmake..."
cmake ..

echo "Building the project..."
make

echo "Running tests with ctest..."
ctest --output-on-failure