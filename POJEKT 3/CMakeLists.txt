cmake_minimum_required(VERSION 3.10)

project(MyGame VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find SDL2 and SDL2_image libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# add executable
add_executable(MyGame main.cpp)

# target_link_libraries
target_link_libraries(MyGame SDL2::Main SDL2::Image)
