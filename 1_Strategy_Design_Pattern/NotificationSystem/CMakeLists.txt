
cmake_minimum_required(VERSION 3.16)

project(NotificationSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    NotificationSystem

    src/main.cpp
    src/NotificationStrategies.cpp
    src/NotificationContext.cpp
)

target_include_directories(
    NotificationSystem
    PRIVATE include
)
