cmake_minimum_required(VERSION 3.10)

project(Snake-Bakcyl VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(Source)
include_directories(Include)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(source_objects_lib OBJECT ${SOURCES})
add_executable(Snake $<TARGET_OBJECTS:source_objects_lib> "main.cpp")
target_link_libraries(Snake ${CURSES_LIBRARIES})
