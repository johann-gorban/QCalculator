cmake_minimum_required(VERSION 3.16)
project(QCalculator)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_CLI "Build the CLI version of the calculator" OFF)
option(BUILD_GUI "Build the GUI version of the calculator" OFF)

add_subdirectory(mathexpr)

if(BUILD_GUI)
    add_subdirectory(gui)
endif()

if(BUILD_CLI)
    add_subdirectory(cli)
endif()