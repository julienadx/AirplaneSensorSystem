cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Server.h data.h Sensor.h Scheduler.h Server.cpp Sensor.cpp Temperature.h Temperature.cpp Humidity.cpp Humidity.h Light.cpp Light.h Sound.cpp Sound.h Scheduler.cpp)