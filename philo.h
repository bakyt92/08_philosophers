
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_args
{
	int number_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int number_each_eat;
} t_args;

int ft_check(int argc, char **argv);


#endif
