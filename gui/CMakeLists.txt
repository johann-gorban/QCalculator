cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

message(status "GUI build enabled")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets UiTools)

qt_standard_project_setup()

file(GLOB_RECURSE GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB_RECURSE GUI_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

qt_add_executable(Calculator
    WIN32 MACOSX_BUNDLE
    ${GUI_HEADERS}
    ${GUI_SOURCES}
)

target_include_directories(Calculator
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Calculator
    PRIVATE
        calculation
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