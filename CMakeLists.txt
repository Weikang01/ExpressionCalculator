cmake_minimum_required(VERSION 3.20)
project(assign02 C)

set(CMAKE_C_STANDARD 99)

add_executable(assign02 main.c parser.h RPN.h operator.h pch.h)
