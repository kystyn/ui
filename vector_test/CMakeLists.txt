cmake_minimum_required(VERSION 3.4)

project(vector_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

find_library(LVECTOR_FOUND NAME vector PATHS ../lib)
find_library(LLOGGER_FOUND NAME logger PATHS ../lib)

if (NOT LVECTOR_FOUND OR NOT LLOGGER_FOUND)
	message(SEND_ERROR "Libraries not found")
	return()
else ()
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LVECTOR_FOUND} ${LLOGGER_FOUND})
endif()
