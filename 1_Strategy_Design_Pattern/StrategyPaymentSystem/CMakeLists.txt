
cmake_minimum_required(VERSION 3.16)

project(StrategyPaymentSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    StrategyPaymentSystem

    src/main.cpp
    src/PaymentStrategies.cpp
    src/PaymentContext.cpp
)

target_include_directories(
    StrategyPaymentSystem
    PRIVATE include
)
