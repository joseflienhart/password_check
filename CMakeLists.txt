cmake_minimum_required(VERSION 4.2)
project(passwort_kontrolle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/joseflienhart/Qt/6.6.1/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(passwort_kontrolle main.cpp
        hauptfenster.cpp
        hauptfenster.h)
target_link_libraries(passwort_kontrolle
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

