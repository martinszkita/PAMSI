cmake_minimum_required(VERSION 3.0)

project(MyProject)

add_executable(przyklad src/main.cpp src/kik.cpp src/board.cpp)
target_include_directories(przyklad PRIVATE inc)
