#include "philo.h"

int ft_end(t_args *args)
{
	size_t i;

	pthread_mutex_unlock(&(args->printing));
	pthread_mutex_destroy(&(args->lt_eating));
	pthread_mutex_destroy(&(args->alive));
	pthread_mutex_destroy(&(args->number_of_meals));
	pthread_mutex_destroy(&(args->printing));
	i = 0;
	while(i < args->number_philo)
	{
		pthread_mutex_unlock(&(args->all_forks[i]));
		pthread_mutex_destroy(&(args->all_forks[i]));
		i++;
	}
	free(args->philosophers);
	free(args->all_forks);
	free(args);
	return (0);
}

int ft_end_dinner(t_args *args)
{
	size_t i;

	i = 0;
	while (i < args->number_philo)
	{
		pthread_detach(args->philosophers[i].philos);
		i++;
	}
	ft_end(args);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args		*args;

	if (ft_check(argc, argv))
	{
		ft_print_error("Wrong arguments\n");
		return (0);
	}
	args = malloc(sizeof(t_args));
	ft_read_args(argv, args);
	if (ft_init_data(args))
		return (1);
	ft_dinner(args);
	ft_check_living(args);
	ft_end_dinner(args);
	return (0);
}
