# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(CPPTests)

# Add Google Test
add_subdirectory(../third_party/googletest googletest)

# Enable testing
enable_testing()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/../include)

# Add test executable
add_executable(linear_algebra_tests test_matrix.cpp)

# Link the test executable with GTest and your source files
target_link_libraries(linear_algebra_tests gtest gtest_main)

# Register the test
add_test(NAME LinearAlgebraTests COMMAND linear_algebra_tests)
