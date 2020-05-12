cmake_minimum_required(VERSION 3.16)
project(company)

set(CMAKE_CXX_STANDARD 11)

add_executable(company src/main.cpp src/worker_Manager.cpp src/worker_Manager.h)