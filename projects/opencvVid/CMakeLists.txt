cmake_minimum_required(VERSION 3.29)
project(opencvVid)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencvVid main.cpp)
target_link_libraries(opencvVid ${OpenCV_LIBS})
