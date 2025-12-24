cmake_minimum_required(VERSION 3.10) # CMake install : https://cmake.org/download/

project(headsUpDisplay LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/Qt/5.14.2/mingw73_64") # Qt Kit Dir

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

set(srcs
    src/main.cpp
    src/headsUpDisplay.cpp
    src/headsUpDisplay.h
    src/headsUpDisplay.ui
    src/systemMonitor.h
    src/systemMonitor.cpp
)

add_executable(${PROJECT_NAME} ${srcs}) 

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets) # Qt5 Shared Library