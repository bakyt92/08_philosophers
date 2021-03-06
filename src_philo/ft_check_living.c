/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_living.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:56 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/26 04:40:04 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	script1(t_args *args, long long timestamp_current, size_t i)
{
	pthread_mutex_unlock(&(args->lt_eating));
	pthread_mutex_lock(&(args->alive));
	args->status_live = i;
	pthread_mutex_unlock(&(args->alive));
	args->death_time = timestamp_current;
	timestamp_current = timestamp_current - args->start_time;
	pthread_mutex_lock(&(args->printing));
	printf("%lld %zu died\n", timestamp_current,
		args->philosophers[i].id_philosopher);
	pthread_mutex_unlock(&(args->printing));
}

void	*ft_check_living(void *args)
{
	t_args	*data;

	data = (t_args *)args;
	while (data->status_live == -1)
	{
		if (ft_living_script(data) == 1)
			break ;
		if (ft_check_nbr_eating(data) == 1)
			break ;
	}
	return (0);
}

int	ft_living_script(t_args *args)
{
	long long	timestamp_current;
	size_t		i;

	i = 1;
	while (i < args->number_philo + 1)
	{
		pthread_mutex_lock(&(args->lt_eating));
		ft_current_time(&timestamp_current);
		if (timestamp_current - args->philosophers[i].time_last_diner
			>= args->time_die)
		{
			script1(args, timestamp_current, i);
			return (1);
		}
		pthread_mutex_unlock(&(args->lt_eating));
		i++;
	}
	return (0);
}

int	ft_check_nbr_eating(t_args *args)
{
	size_t	i;
	size_t	counter;

	i = 1;
	counter = 0;
	if (args->number_each_eat > 0)
	{
		while (i < args->number_philo + 1)
		{
			pthread_mutex_lock(&(args->number_of_meals));
			if (args->philosophers[i].number_dining >= args->number_each_eat)
				counter++;
			pthread_mutex_unlock(&(args->number_of_meals));
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
