cmake_minimum_required(VERSION 3.10)
project(gtest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(fltk "${CMAKE_CURRENT_SOURCE_DIR}/lib/fltk")
add_subdirectory(${fltk})

add_executable(gtest src/main.cpp)

target_link_libraries(gtest PRIVATE fltk)