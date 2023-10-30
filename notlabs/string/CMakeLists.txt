cmake_minimum_required(VERSION 3.5.1)
project(notlabs CXX)

set(SRC main.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER g++)

add_executable(${PROJECT_NAME} ${SRC})

