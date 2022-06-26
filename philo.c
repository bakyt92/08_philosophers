/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:55:40 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/26 15:43:22 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_destroy_mutex(t_args *args)
{
	size_t	i;

	pthread_mutex_unlock(&(args->printing));
	if (pthread_mutex_destroy(&(args->printing)))
		ft_print_error("Error: Mutex_destroy printing\n");
	if (pthread_mutex_destroy(&(args->lt_eating)))
		ft_print_error("Error: Mutex_destroy lt_eating\n");
	if (pthread_mutex_destroy(&(args->alive)))
		ft_print_error("Error: Mutex_destroy alive\n");
	if (args->number_each_eat > 0)
	{
		if (pthread_mutex_destroy(&(args->number_of_meals)))
			ft_print_error("Error: Mutex_destroy number of meals\n");
	}
	i = 1;
	while (i < args->number_philo + 1)
	{
		pthread_mutex_unlock(&(args->all_forks[i]));
		if (pthread_mutex_destroy(&(args->all_forks[i])))
			ft_print_error("Error: Mutex_destroy all forks \n");
		i++;
	}
	return (0);
}

int	ft_end(t_args *args)
{
	ft_destroy_mutex(args);
	if (args->philosophers)
		free(args->philosophers);
	if (args->all_forks)
		free(args->all_forks);
	if (args)
		free(args);
	return (0);
}

void	ft_end_dinner(t_args *args)
{
	size_t	i;

	i = 1;
	while (i < args->number_philo + 1)
	{
		pthread_join(args->philosophers[i].philos, NULL);
		i++;
	}
	ft_end(args);
	return ;
}

int	main(int argc, char **argv)
{
	t_args		*args;
	pthread_t	death_check;

	if (ft_check(argc, argv))
	{
		ft_print_error("Wrong arguments\n");
		return (1);
	}
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	ft_read_args(argv, args);
	if (ft_init_data(args))
	{
		ft_end(args);
		return (1);
	}
	ft_dinner(args);
	pthread_create(&death_check, NULL, ft_check_living, (void *)(args));
	pthread_join(death_check, NULL);
	ft_end_dinner(args);
	return (0);
}
