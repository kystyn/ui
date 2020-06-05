project(compact_test)

cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(LLOGGER_FOUND NAME logger PATHS libs)
find_library(LVECTOR_FOUND NAME vector PATHS libs)
find_library(LCOMPACT_FOUND NAME compact PATHS libs)

if (NOT LLOGGER_FOUND OR NOT LVECTOR_FOUND OR NOT LCOMPACT_FOUND)
	message(SEND_ERROR "Libraries were not found")
else()
	add_executable(${PROJECT_NAME} src/main.cpp)
        target_link_libraries(${PROJECT_NAME} ${LLOGGER_FOUND} ${LVECTOR_FOUND} ${LCOMPACT_FOUND})
endif()

