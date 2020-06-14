cmake_minimum_required(VERSION 3.4)

project(vector)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED src/vector_impl.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
