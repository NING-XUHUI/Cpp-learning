cmake_minimum_required(VERSION 3.15)
project(nba)

set(CMAKE_CXX_STANDARD 20)

add_executable(nba main.cpp src/sourse/Player.cpp src/head/Player.h src/sourse/viewController.cpp src/head/viewController.h)