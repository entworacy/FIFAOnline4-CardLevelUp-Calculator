cmake_minimum_required(VERSION 3.26)
project(fifa_cardlvup_calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(fifa_cardlvup_calculator main.c
        calculator.c
        calculator.h)
