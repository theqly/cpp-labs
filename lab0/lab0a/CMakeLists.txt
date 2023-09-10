cmake_minimum_required(VERSION 3.5.1)
project(lab0a CXX)

set(SRC main.cpp module1.cpp module2.cpp module3.cpp)

add_executable(${PROJECT_NAME} ${SRC})

