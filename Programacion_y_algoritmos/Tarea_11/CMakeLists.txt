cmake_minimum_required(VERSION 2.4)

project(hello_world)

include_directories(Modules/)
add_executable(Main.out main.cpp Modules/employee_class.cpp)
