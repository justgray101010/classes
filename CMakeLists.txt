project(devices)
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.17)
include_directories(inc src)

string(REGEX REPLACE "/W[3|4]" "/w" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(main main.cpp src/date.cpp src/channel.cpp src/device.cpp src/sensor.cpp)