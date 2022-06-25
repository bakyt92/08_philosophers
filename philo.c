/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:55:40 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:04:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// перед каждлым мьютексом написать вывод ошибки, если она есть
int	ft_end(t_args *args)
{
	size_t	i;

	pthread_mutex_unlock(&(args->printing));
	pthread_mutex_destroy(&(args->printing));
	pthread_mutex_destroy(&(args->lt_eating));
	pthread_mutex_destroy(&(args->alive));
	pthread_mutex_destroy(&(args->number_of_meals));
	i = 1;
	while (i < args->number_philo + 1)
	{
		pthread_mutex_unlock(&(args->all_forks[i]));
		pthread_mutex_destroy(&(args->all_forks[i]));
		i++;
	}
	if (args->philosophers)
		free(args->philosophers);
	if (args->all_forks)
		free(args->all_forks);
	if (args)
		free(args);
	return (0);
}

//int ft_end_dinner(t_args *args)
void	ft_end_dinner(t_args *args)
{
	size_t	i;
//	long long	current_time;

	i = 1;
	while (i < args->number_philo + 1)
	{
		pthread_join(args->philosophers[i].philos, NULL);
		i++;
	}
//	ft_current_time(&current_time);
//	printf("%lld %d died_struct\n", current_time - args->start_time, args->status_live);
//	pthread_mutex_unlock(&(args->printing));
	ft_end(args);
//	return (0);
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
//	ft_check_living(args);
	ft_end_dinner(args);
	return (0);
}

/// не забыть обработать вариант с 1 философом и mutex destroy