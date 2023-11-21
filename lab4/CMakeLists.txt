cmake_minimum_required(VERSION 3.5.1)
project(lab4 CXX)

set(CMAKE_CXX_STANDARD 21)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(lab4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

