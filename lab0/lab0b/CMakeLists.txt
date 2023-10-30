cmake_minimum_required(VERSION 3.5.1)
project(lab0b CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp
        src/word.cpp
        src/reader.cpp
        src/writer.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(lab0b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test1 test/test.cpp)

target_include_directories(test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(test1 GTest::gtest_main)