cmake_minimum_required(VERSION 3.4)

project(vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED vector_impl.cpp)
find_library(LLOGGER_FOUND logger PATHS ../lib)

if (NOT LLOGGER_FOUND)
	message(SEND_ERROR "Logger not found")
else()
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LLOGGER_FOUND})
endif()

