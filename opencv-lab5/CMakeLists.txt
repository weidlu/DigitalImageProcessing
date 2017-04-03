cmake_minimum_required(VERSION 2.8)
project(lab1.5)
find_package(OpenCV REQUIRED)
add_executable(Frequency fdma.cpp)
target_link_libraries(Frequency ${OpenCV_LIBS})

