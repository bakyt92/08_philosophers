/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_living.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:56 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:07:57 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_check_living(void *args)
{
	t_args *Data;

	Data = (t_args *)args;
	while (Data->status_live == 1)
	{
		if (ft_living_script(Data) == 1)
			break ;
		if (ft_check_nbr_eating(Data) == 1)
			break ;
	}
	return (0);
}

int	ft_living_script(t_args *args)
{
	size_t	timestamp_current;
	size_t	i;

	i = 0;
	ft_current_time(&timestamp_current);
	while (i < args->number_philo)
	{
		pthread_mutex_lock(&(args->lt_eating));
		if (timestamp_current - args->philosophers[i].time_last_diner >
			args->time_die)
		{
			pthread_mutex_unlock(&(args->lt_eating));
			ft_print_data("%zu %zu died\n", &(args->philosophers[i]), args);
			pthread_mutex_lock(&(args->alive));
			args->status_live = 0;
			pthread_mutex_unlock(&(args->alive));
			return (1);
		}
		pthread_mutex_unlock(&(args->lt_eating));
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