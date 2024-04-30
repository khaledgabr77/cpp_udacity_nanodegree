cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project(ExampleProjectCMakeLists)

add_executable(khaled src/main.cpp src/vect_add_one.cpp src/increment_and_sum.cpp)
