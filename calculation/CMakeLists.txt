cmake_minimum_required(VERSION 3.16)
project(Calculation)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE CALCULATION_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

add_library(Calculation STATIC
    ${CALCULATION_SOURCES}
)

target_include_directories(Calculation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
