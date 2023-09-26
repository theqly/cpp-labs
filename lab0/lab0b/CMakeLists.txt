cmake_minimum_required(VERSION 3.5.1)
project(lab0b CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp
        src/word.cpp
        src/handler.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(lab0b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(hash_table_test test/test.cpp)
target_link_libraries(hash_table_test GTest::gtest_main)
