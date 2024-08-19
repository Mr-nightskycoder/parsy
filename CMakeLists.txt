cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Parsy VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the source files
file(GLOB_RECURSE PARSY_HEADERS "include/parsy/*.hpp")

# Add a library target
# Use only one library target, parsy_lib, to avoid naming conflicts
add_library(parsy_lib ${PARSY_HEADERS} src/parsy.cpp)

# Enable testing
enable_testing()

# Add test executable
add_executable(test_digit tests/test_digit.cpp)

# Link the test executable with the parsy library
target_link_libraries(test_digit parsy_lib)

# Add a test
add_test(NAME DigitTest COMMAND test_digit)