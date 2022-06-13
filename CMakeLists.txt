cmake_minimum_required(VERSION 3.21)
project(08_philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(08_philosophers philo.c philo.h src_philo/ft_check.c src_philo/ft_read_args.c src_philo/ft_atoi.c src_philo/ft_process_threads.c src_philo/ft_dinner.c src_philo/ft_simulation.c src_philo/ft_time.c src_philo/ft_cycle.c src_philo/ft_if_alive.c src_philo/ft_print_error.c src_philo/ft_check_living.c)
