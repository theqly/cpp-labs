cmake_minimum_required(VERSION 3.5.1)
project(hash_table CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(exe_name ${PROJECT_NAME})

set(SRC src/main.cpp src/hash_table.cpp)

add_executable(${exe_name} ${SRC})

target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(hash_table_test test/test1.cpp)
target_include_directories(hash_table_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(hash_table_test GTest::gtest_main)
