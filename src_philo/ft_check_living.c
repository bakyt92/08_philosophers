#include "../philo.h"

int	ft_check_living(t_args *args)
{
	while (args->status_live == 1)
	{
		if (ft_living_script(args) == 1)
			break ;
		if (ft_check_nbr_eating(args) == 1)
			break ;
	}
	return (0);
}

int	ft_living_script(t_args *args)
{
	size_t	timestamp_current;
	size_t 	i;

	i = 0;
	ft_current_time(&timestamp_current);
	while (i < args->number_philo)
	{

		if (timestamp_current - args->philosophers[i].time_last_diner >
			args->time_die)
		{
			printf("TIME: %zu\n", timestamp_current - args->philosophers[i]
			.time_last_diner);
			pthread_mutex_lock(&(args->alive));
			pthread_mutex_lock(&(args->printing));
			ft_print_data("%zu %zu died\n", args, &(args->philosophers[i]));
			args->status_live = 0;
			pthread_mutex_unlock(&(args->printing));
			pthread_mutex_unlock(&(args->alive));
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_check_nbr_eating(t_args *args)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (args->number_each_eat > 0)
	{
		while (i < args->number_philo)
		{
			if (args->philosophers[i].number_dining >= args->number_each_eat)
				counter++;
			i++;
		}
		if (counter == args->number_philo)
		{
			pthread_mutex_lock(&(args->alive));
			args->status_live = 0;
			pthread_mutex_unlock(&(args->alive));
			return (1);
		}
	}
	return (0);
}