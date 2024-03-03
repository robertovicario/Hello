cmake_minimum_required(VERSION 3.10)
project(YAML_CPP_Example)

# Find yaml-cpp package
find_package(yaml-cpp REQUIRED)

# Add executable target
add_executable(main main.cpp)

# Link yaml-cpp library
target_link_libraries(main PRIVATE yaml-cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
