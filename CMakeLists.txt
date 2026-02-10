cmake_minimum_required(VERSION 3.16)
project(computer_calculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)
if (NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Core Gui Widgets)
endif()

add_executable(computer_calculator
    src/qt_main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

if (Qt6_FOUND)
    target_link_libraries(computer_calculator PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
else()
    target_link_libraries(computer_calculator PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
endif()

set_target_properties(computer_calculator PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
