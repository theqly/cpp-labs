cmake_minimum_required(VERSION 3.5.1)
project(hash_table)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(exe_name ${PROJECT_NAME})

set(SRC src/main.cpp src/hash_table.cpp)

add_executable(${exe_name} ${SRC})

target_include_directories(hash_table PUBLIC include)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# описываем исполняемый файл программы для запуска тестов: это cpp-файлы тестов + основная библиотека + библиотека gtest_main
# наш собственный main.cpp здесь не нужен, т.к. функция main реализована в gtest_main
add_executable(hash_table_test test/test1.cpp)
target_link_libraries(hash_table_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hash_table_test)