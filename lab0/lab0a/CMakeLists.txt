<<<<<<< HEAD
cmake_minimum_required(VERSION 3.5.1)
project(lab0a CXX)

set(SRC main.cpp module1.cpp module2.cpp module3.cpp)

add_executable(${PROJECT_NAME} ${SRC})

=======
cmake_minimum_required(VERSION 3.5.1)
project(lab0a)

set(SRC main.cpp module1.cpp module2.cpp module3.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} ${SRC})

>>>>>>> d79e4b81c62502c0f6f794f017bad8dd3bdc4b99
