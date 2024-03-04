cmake_minimum_required(VERSION 3.10)
project(example)

# pkg
find_package(yaml-cpp REQUIRED)

# exe
add_executable(balance balance.cpp)

# lib
target_link_libraries(balance PRIVATE yaml-cpp)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
