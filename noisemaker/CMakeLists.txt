cmake_minimum_required(VERSION 2.8)
project(lab1.4)
find_package(OpenCV REQUIRED)
add_executable(Noise noise.cpp)
target_link_libraries(Noise ${OpenCV_LIBS})

