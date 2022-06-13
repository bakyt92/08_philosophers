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

	ft_current_time(&timestamp_current);
	if (timestamp_current -
		args->philosophers[args->number_philo].time_last_diner > args->time_die)
	{
		pthread_mutex_lock(&(args->alive));
		pthread_mutex_lock(&(args->printing));
		args->status_live = 0;
		ft_print_data("%zu %zu died\n", args);
		pthread_mutex_unlock(&(args->printing));
		pthread_mutex_unlock(&(args->alive));
	}
}

int ft_check_nbr_eating(t_args *args)
{
	
}