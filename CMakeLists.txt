cmake_minimum_required(VERSION 3.21)
project(08_philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(08_philosophers main.c philo.h src_philo/ft_check.c src_philo/ft_read_argc.c)
