# You are free to modify this file
cmake_minimum_required(VERSION 3.5)
project(game)
find_package(X11 REQUIRED)
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SRC_FILES 
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.hpp
    ${SRC_DIR}/*.h
)

add_executable(game ${SRC_FILES})
target_link_libraries(game m X11)
