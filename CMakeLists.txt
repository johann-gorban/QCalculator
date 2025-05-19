cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

# --- Опции ---
option(BUILD_CLI "Build the CLI version of the calculator" OFF)
option(BUILD_GUI "Build the GUI version of the calculator" OFF)
option(BUILD_TESTS "Build unit tests" OFF)

# --- Общие исходники ---
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
    source/translating/translator.cpp
    source/translating/command_manager.cpp
    source/translating/commands.cpp
    source/computation/calculator.cpp
    source/facade.cpp
    source/memory/memory.cpp
    source/history/history.cpp
)

if(BUILD_CLI)
    message(STATUS "CLI build enabled")

    set(CLI_SOURCES
        source/cli/main.cpp
        source/cli/commands.cpp
        source/cli/menu.cpp
    )

    add_executable(Calculator ${CORE_SOURCES} ${CLI_SOURCES})
    target_include_directories(Calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
    target_include_directories(Calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

elseif(BUILD_GUI)
    message(STATUS "GUI build enabled")

    find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets UiTools)

    qt_standard_project_setup()

    set(SOURCE_GUI_FILES
        source/gui/main.cpp
        source/gui/mainwindow.cpp
    )

    set(HEADER_GUI_FILES
        include/gui/mainwindow.hpp
    )

    qt_add_executable(Calculator
        WIN32 MACOSX_BUNDLE
        ${SOURCE_GUI_FILES}
        ${HEADER_GUI_FILES}
    )

    target_include_directories(Calculator
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    target_link_libraries(Calculator
        PRIVATE
            Qt::Core
            Qt::Widgets
            Qt6::UiTools
    )

    include(GNUInstallDirs)

    install(TARGETS Calculator
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

    qt_generate_deploy_app_script(
        TARGET Calculator
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
    )

    install(SCRIPT ${deploy_script}) 

elseif(BUILD_TESTS)
    message(STATUS "Test build enabled")

    enable_testing()
    add_subdirectory(tests)

else()
    message(FATAL_ERROR "You must specify exactly one build option: BUILD_CLI=ON, BUILD_GUI=ON or BUILD_TESTS=ON")
endif()

