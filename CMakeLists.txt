cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -ggdb)

set(CORE_SOURCES
    source/token_manager.cpp
    
    source/tokenization/context.cpp 
    source/tokenization/tokenizer.cpp
    source/tokenization/tokens.cpp
    source/tokenization/states.cpp
    source/tokenization/state_factory.cpp

    source/parsing/extended_tokens.cpp
    source/parsing/parser_context.cpp
    source/parsing/parser.cpp
    source/parsing/states.cpp

    source/sorting/sorter.cpp
    source/sorting/command_manager.cpp
    source/sorting/commands.cpp
)

set(TEST "" CACHE STRING "Test name to build")

if(TEST)
    add_executable(test_${TEST} ${CORE_SOURCES} "tests/${TEST}.cpp")
    target_include_directories(test_${TEST} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    message(STATUS "Building test: ${TEST}.cpp")
else()
    add_executable(algrebrator.out ${CORE_SOURCES} "source/main.cpp")
    target_include_directories(algrebrator.out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    message(STATUS "Building main program")
endif()