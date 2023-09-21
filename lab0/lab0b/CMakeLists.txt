cmake_minimum_required(VERSION 3.5.1)
project(lab0b CXX)

set(CMAKE_CXX_STANDARD 17)
set(SRC src/main.cpp
        src/word.cpp)

set(CMAKE_PROJECT_INCLUDE ./include)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(lab0b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

