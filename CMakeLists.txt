cmake_minimum_required(VERSION 3.17)
project(OOProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOProject main.cpp include/Participant.h src/Participant.cpp src/Admin.cpp include/Admin.h src/User.cpp include/User.h src/Guest.cpp include/Guest.h)