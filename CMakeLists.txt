cmake_minimum_required(VERSION 3.17)
project(assignment-1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

add_executable(
    assignment-1
    main.cpp
    contact.cpp
    contact.h
    contact_list.cpp
    contact_list.h
)

add_library(libassignment-1 STATIC contact.cpp)