cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройки для отладки
set(CMAKE_BUILD_TYPE Debug)  # Автоматически добавляет -g для GCC
add_compile_options(-Wall -ggdb)  # -ggdb для расширенной информации GDB

set(SOURCES
    source/tokens.cpp
    source/calculator.cpp
    source/command_manager.cpp
    source/commands.cpp
    source/lexer_context.cpp
    source/lexer.cpp
    source/token_manager.cpp
    source/cleaner.cpp
    source/states.cpp
    tests/first.cpp
)

add_executable(prog.out ${SOURCES})

target_include_directories(prog.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)