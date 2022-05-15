#include "../philo.h"

void	ft_read_args(char **argv, t_args *args)
{
	args->number_philo = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep= ft_atoi(argv[4]);
	if (argv[5])
		args->number_each_eat = ft_atoi(argv[5]);
	else
		args->number_each_eat = -1;
}