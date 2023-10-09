cmake_minimum_required(VERSION 3.16.3)

project(thegame CXX)
set(CXX "clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB_RECURSE src "src/*.cpp")

add_executable(thegame ${src})
target_link_libraries(thegame)
