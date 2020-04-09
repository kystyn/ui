cmake_minimum_required(VERSION 3.8)

project(logger)

add_library(${PROJECT_NAME} SHARED ILogger.h logger_impl.cpp RC.h)
