cmake_minimum_required(VERSION 3.17)
project(assignment-1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

set(
    SOURCES
    contact.cpp
    contact_list.cpp
)

add_executable(assignment-1 main.cpp ${SOURCES})

add_library(libassignment-1 STATIC ${SOURCES})