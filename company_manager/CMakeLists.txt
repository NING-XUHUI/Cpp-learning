cmake_minimum_required(VERSION 3.16)
project(company_manager)

set(CMAKE_CXX_STANDARD 11)

add_executable(company_manager 职工管理系统.cpp src/WorkerManager.cpp src/WorkerManager.h)