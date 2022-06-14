#include "../philo.h"

int	ft_init_data(t_args *args)
{
	if (ft_create_forks(args))
		return (1);
	if (ft_create_philosophers(args))
		return (1);
	if (ft_create_mutex(args))
		return (1);
	args->status_live = 1;
	return (0);
}

int	ft_create_mutex(t_args *args)
{
	if (pthread_mutex_init(&(args->alive), NULL))
		return (1);
	if (pthread_mutex_init(&(args->printing), NULL))
		return (1);
	if (pthread_mutex_init(&(args->lt_eating), NULL))
		return (1);
	if (args->number_each_eat > 0)
	{
		if (pthread_mutex_init(&(args->number_of_meals), NULL))
			return (1);
	}
	return (0);
}

int	ft_create_forks(t_args *args)
{
	size_t i;

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
	size_t timestamp_start;

	args->philosophers = malloc(sizeof(t_Data) * args->number_philo);
	if (!args->philosophers)
		return (1);
	i = 0;
	while (i < args->number_philo)
	{
//		printf("TEST 0: philo num, %zu\n", args->number_philo);
		args->philosophers[i].id_philosopher = i;
		args->philosophers[i].right_fork = &args->all_forks[i];
		args->philosophers[i].left_fork = &args->all_forks[(i + 1) % args->number_philo];
		ft_current_time(&timestamp_start);
		args->philosophers[i].time_last_diner = timestamp_start;
		args->philosophers[i].number_dining = 0;
		args->philosophers[i].args1 = args;
		i++;
	}
	i = 0;
//	printf("TEST 1: philo num, %zu\n", args->number_philo);
//	while(i < args->number_philo)
//	{
//		printf("TEST 2: philo num, %zu", args->philosophers[i].id_philosopher);
//		i++;
//	}
	return (0);
}