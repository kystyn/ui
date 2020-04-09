cmake_minimum_required(VERSION 3.4)

project(vector_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

find_library(VECTOR_LIB vector)
target_link_libraries(${PROJECT_NAME} PUBLIC ${VECTOR_LIB_LIBRARIES})
