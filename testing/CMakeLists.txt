cmake_minimum_required(VERSION 3.16)
project(testing C)

set(CMAKE_C_STANDARD 99)

add_executable(testing main.c philo.c)
