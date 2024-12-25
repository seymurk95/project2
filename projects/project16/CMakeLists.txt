cmake_minimum_required(VERSION 3.29)
project(project16)

set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)

add_executable(project16 main4.cpp)

TARGET_LINK_LIBRARIES(project16 Boost::program_options)

