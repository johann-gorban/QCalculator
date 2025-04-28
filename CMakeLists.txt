cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Equivalent to Makefile's -Wall
add_compile_options(-Wall)


# Explicit source list matching Makefile's SRC
set(SOURCES
    source/tokens.cpp
)

# Create executable (matches Makefile's TARGET)
add_executable(prog.out ${SOURCES})

# Equivalent to Makefile's -Iinclude
target_include_directories(prog.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)