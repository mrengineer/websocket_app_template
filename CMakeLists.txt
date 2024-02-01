cmake_minimum_required(VERSION 3.5.2)
project(checker C)

set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(include)
add_executable(app src/main.c)
