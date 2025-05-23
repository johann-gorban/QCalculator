cmake_minimum_required(VERSION 3.16)
project(QCalculator)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_CLI "Build the CLI version of the calculator" OFF)
option(BUILD_GUI "Build the GUI version of the calculator" OFF)
option(BUILD_TESTS "Build unit tests" OFF)

add_subdirectory(calculation)

if(BUILD_GUI)
    add_subdirectory(gui)
endif()

if(BUILD_CLI)
    add_subdirectory(cli)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
