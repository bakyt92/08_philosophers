/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:14 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/26 04:41:21 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_data(t_args *args)
{
	if (ft_create_forks(args))
		return (1);
	if (ft_create_philosophers(args))
		return (1);
	if (ft_create_mutex(args))
		return (1);
	args->status_live = -1;
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
	size_t	i;

	i = 1;
	args->all_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args->number_philo);
	if (!args->all_forks)
		return (1);
	while (i < args->number_philo + 1)
	{
		pthread_mutex_init(&args->all_forks[i], NULL);
		i++;
	}
	return (0);
}

int	ft_create_philosophers(t_args *args)
{
	size_t		i;
	long long	timestamp_start;

	args->philosophers = malloc(sizeof(t_Data) * args->number_philo);
	if (!args->philosophers)
		return (1);
	i = 1;
	ft_current_time(&timestamp_start);
	while (i < args->number_philo + 1)
	{
		args->philosophers[i].id_philosopher = i;
		args->philosophers[i].right_fork = &args->all_forks[i];
		if (i == args->number_philo)
			args->philosophers[i].left_fork = &args->all_forks[1];
		else
			args->philosophers[i].left_fork = &args->all_forks[(i + 1)];
		args->philosophers[i].time_last_diner = timestamp_start;
		args->philosophers[i].number_dining = 0;
		args->philosophers[i].args1 = args;
		i++;
	}
	i = 0;
	return (0);
}
