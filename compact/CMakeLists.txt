project(compact)

cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_FIND_LIBRARY_PREFIXES "" "lib")

add_library(${PROJECT_NAME} SHARED src/compact_impl.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

find_library(LLOGGER_FOUND NAMES logger PATHS libs)
find_library(LVECTOR_FOUND NAMES vector PATHS libs)

if (NOT LLOGGER_FOUND OR NOT LVECTOR_FOUND)
	message(SEND_ERROR "Libraries not found")
else()
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LLOGGER_FOUND} ${LVECTOR_FOUND})
endif()

