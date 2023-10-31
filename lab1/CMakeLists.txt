cmake_minimum_required(VERSION 3.5.1)
project(lab1 CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC src/main.cpp src/bitarray.cpp)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(lab1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab1_test test/test1.cpp)
target_include_directories(lab1_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(lab1_test GTest::gtest_main)
