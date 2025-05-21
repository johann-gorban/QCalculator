cmake_minimum_required(VERSION 3.16)
project(Calculation)

set(CMAKE_CXX_STANDARD 17)

set(CALCULATION_SOURCES
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
    source/sorting/sort_command_manager.cpp
    source/sorting/sort_commands.cpp
    source/translating/translator.cpp
    source/translating/command_manager.cpp
    source/translating/commands.cpp
    source/computation/calculator.cpp
    source/facade.cpp
    source/memory/memory.cpp
    source/history/history.cpp
)

add_library(Calculation STATIC
    ${CALCULATION_SOURCES}
)

target_include_directories(Calculation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
