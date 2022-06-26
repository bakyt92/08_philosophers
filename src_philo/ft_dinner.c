/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/26 04:45:30 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_print_data(char *text, t_Data *philosopher_cur, t_args *alldata)
{
	long long	time_now;

	if (ft_if_alive(alldata))
		return (1);
	else
	{
		pthread_mutex_lock(&(alldata->printing));
		ft_current_time(&time_now);
		time_now = time_now - alldata->start_time;
		printf(text, time_now, philosopher_cur->id_philosopher);
		pthread_mutex_unlock(&(alldata->printing));
	}
	return (0);
}

int	ft_dinner(t_args *args)
{
	size_t	i;

	i = 1;
	ft_current_time(&(args->start_time));
	if (args->number_philo == 1)
	{
		ft_thinking(&(args->philosophers[1]), args);
		pthread_mutex_lock(args->philosophers[1].left_fork);
		if (ft_print_data("%lld %zu has taken a fork\n",
				&(args->philosophers[1]), args))
		{
			pthread_mutex_unlock(args->philosophers[1].left_fork);
			return (0);
		}
		return (0);
	}
	while (i < args->number_philo + 1)
	{
		pthread_create(&(args->philosophers[i].philos), NULL, ft_simulation,
			(void *)(&args->philosophers[i]));
		i++;
	}
	return (0);
}
