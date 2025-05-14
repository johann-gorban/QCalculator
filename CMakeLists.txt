cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройки для отладки
set(CMAKE_BUILD_TYPE Debug)  # Автоматически добавляет -g для GCC
add_compile_options(-Wall -ggdb)  # -ggdb для расширенной информации GDB

set(SOURCES
    source/token_manager.cpp
    # Tokenization
    source/tokenization/context.cpp 
    source/tokenization/tokenizer.cpp
    source/tokenization/tokens.cpp
    source/tokenization/states.cpp
    source/tokenization/state_factory.cpp
    
    # Parsing
    source/parsing/extended_tokens.cpp
    source/parsing/parser_context.cpp
    source/parsing/parser.cpp
    source/parsing/states.cpp

    # Sorting 
    source/sorting/sorter.cpp
)

add_executable(prog.out ${SOURCES})

target_include_directories(prog.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)