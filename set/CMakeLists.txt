cmake_minimum_required(VERSION 3.5)

project(set LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(set SHARED src/set_impl.cpp include/ISet.h)
