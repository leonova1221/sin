cmake_minimum_required(VERSION 3.5)

project(prof20201010-Morozov LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(prof20201010-Morozov ${SDL2_INCLUDE_DIRS})

add_executable(prof20201010-Morozov main.cpp)
target_link_libraries(prof20201010-Morozov ${SDL2_LIBRARIES})
