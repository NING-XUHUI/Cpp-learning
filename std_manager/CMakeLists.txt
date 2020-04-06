cmake_minimum_required(VERSION 3.15)
project(std_manager)

set(CMAKE_CXX_STANDARD 11)

add_executable(std_manager main.cpp StudentModel.cpp ManagerController.cpp ManagerController.h ManagerView.cpp ManagerView.h s.h)