cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройки для отладки
set(CMAKE_BUILD_TYPE Debug)  # Автоматически добавляет -g для GCC
add_compile_options(-Wall -ggdb)  # -ggdb для расширенной информации GDB

set(SOURCES
    source/tokenization/context.cpp
    source/tokenization/manager.cpp
    source/tokenization/tokenizer.cpp
    source/tokenization/tokens.cpp
    source/tokenization/states.cpp
    source/tokenization/state_factory.cpp
    tests/tokenization.cpp
)

add_executable(prog.out ${SOURCES})

target_include_directories(prog.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)