cmake_minimum_required(VERSION 3.16)

project(app VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main graph dijkstras)
