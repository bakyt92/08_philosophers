#include "../philo.h"

int	ft_init_data(t_args *args)
{
	if (ft_create_forks(args))
		return (1);
	if (ft_create_philosophers(args))
		return (1);
	return (0);
}

int	ft_create_forks(t_args *args)
{
	int i;

	i = 0;
	args->all_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* args->number_philo);
	if (!args->all_forks)
		return (1);
	while (i < args->number_philo)
	{
		pthread_mutex_init(&(args->all_forks[i]), NULL);
		i++;
	}
	return (0);
}

int ft_create_philosophers(t_args *args)
{
	size_t i;

	args->philosophers = malloc(sizeof(t_Data) * args->number_philo);
	if (!args->philosophers)
		return (1);
	i = 0;
	while (i < args->number_philo)
	{
		args->philosophers[i].id_philosopher = i;
		args->philosophers[i].right_fork = &(args->all_forks[i]);
		args->philosophers[i].left_fork = &(args->all_forks[(i + 1) % args->number_philo]);
		i++;
	}
	return (0);
}