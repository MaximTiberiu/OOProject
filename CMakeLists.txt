cmake_minimum_required(VERSION 3.17)
project(OOProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOProject main.cpp include/Participant.h src/Participant.cpp src/Admin.cpp include/Admin.h src/User.cpp include/User.h src/Guest.cpp include/Guest.h src/Interface.cpp include/Interface.h src/Post.cpp include/Post.h src/Channel.cpp include/Channel.h src/LoginWrapper.cpp include/LoginWrapper.h)