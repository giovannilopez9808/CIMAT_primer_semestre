cmake_minimum_required(VERSION 2.4)

project(hello_world)

set(CMAKE_CXX_STANDARD 17)
include_directories(Modules/)
add_executable(Main.out main.cpp)
