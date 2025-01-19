cmake_minimum_required(VERSION 3.14)
project(linear_algebra CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create library from your source files
add_library(linear_algebra_lib
    src/matrix.cpp
    # Add vectors.cpp when you create it
    # src/vectors.cpp
)

# Add include directory
target_include_directories(linear_algebra_lib
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Enable testing
enable_testing()

# Add the tests directory
add_subdirectory(tests)
