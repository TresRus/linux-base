cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

project(forkstdout)

set(SOURCE_FILES source/forkstdout.cpp)

add_executable(forkstdout ${SOURCE_FILES})