cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE CLI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

add_executable(Calculator ${CLI_SOURCES})

target_include_directories(Calculator
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Calculator
    calculation
)

