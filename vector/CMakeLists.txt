cmake_minimum_required(VERSION 3.4)

project(vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED vector_impl.cpp)
find_library(LOGGER_LIB logger)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LOGGER_LIB_LIBRARIES})

