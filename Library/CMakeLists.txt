cmake_minimum_required(VERSION 3.16)
project(Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library main.cpp User.cpp User.h Menu.cpp Menu.h TP.h Book.cpp Book.h Date.cpp Date.h)