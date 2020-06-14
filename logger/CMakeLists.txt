cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(logger)

add_library(${PROJECT_NAME} SHARED src/logger_impl.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
