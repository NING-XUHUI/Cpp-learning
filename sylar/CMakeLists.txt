cmake_minimum_required(VERSION 3.17)
project(sylar)

set(CMAKE_CXX_STANDARD 11)

add_executable(sylar main.cpp sylar/log.h sylar/log.cc)