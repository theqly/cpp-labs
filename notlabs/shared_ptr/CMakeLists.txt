cmake_minimum_required(VERSION 3.5.1)
project(shared_ptr CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(shared_ptr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)