cmake_minimum_required(VERSION 3.5)

project(set_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

find_library(LLOGGER_FOUND NAMES logger PATHS ../lib)
find_library(LVECTOR_FOUND NAMES vector PATHS ../lib)
find_library(LSET_FOUND NAMES set PATHS ../lib)

if (NOT LVECTOR_FOUND OR NOT LLOGGER_FOUND OR NOT LSET_FOUND)
	message(SEND_ERROR "Libraries not found")
else()
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LVECTOR_FOUND} ${LLOGGER_FOUND} ${LSET_FOUND})
endif()
