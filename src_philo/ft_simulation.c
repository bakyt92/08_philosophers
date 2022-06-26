/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:01 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/26 04:56:05 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_begin(t_args	*alldata, t_Data *philosopher_cur)
{
	if (ft_if_alive(alldata))
		return (1);
	pthread_mutex_lock(philosopher_cur->left_fork);
	if (ft_print_data("%lld %zu has taken a fork\n",
			philosopher_cur, alldata))
	{
		pthread_mutex_unlock(philosopher_cur->left_fork);
		return (1);
	}
	if (ft_if_alive(alldata))
	{
		pthread_mutex_unlock(philosopher_cur->left_fork);
		return (1);
	}
	pthread_mutex_lock(philosopher_cur->right_fork);
	if (ft_print_data("%lld %zu has taken a fork\n",
			philosopher_cur, alldata))
	{
		pthread_mutex_unlock(philosopher_cur->left_fork);
		pthread_mutex_unlock(philosopher_cur->right_fork);
		return (1);
	}
	return (0);
}

int	ft_thinking(t_Data *philosopher_cur, t_args *alldata)
{
	if (ft_print_data("%lld %zu is thinking\n", philosopher_cur, alldata))
		return (1);
	else
		return (0);
}

static int	ft_sleeping(t_Data *philosopher_cur, t_args *alldata)
{
	if (ft_print_data("%lld %zu is sleeping\n", philosopher_cur, alldata))
		return (1);
	else
	{
		ft_smart_sleep(alldata->time_sleep);
		return (0);
	}
}

void	*ft_simulation(void *cur_philosopher)
{
	t_Data	*philosopher_cur;
	t_args	*alldata;

	philosopher_cur = (t_Data *)cur_philosopher;
	alldata = philosopher_cur->args1;
	if (ft_if_alive(alldata))
		return (NULL);
	if (philosopher_cur->id_philosopher % 2 == 0)
		ft_thinking(philosopher_cur, alldata);
	else
	{
		ft_thinking(philosopher_cur, alldata);
		ft_smart_sleep(alldata->time_eat);
	}
	while (1)
	{
		if (ft_begin(philosopher_cur, alldata))
			return (0);
		if (ft_print_data("%lld %zu is eating\n", philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			pthread_mutex_unlock(philosopher_cur->right_fork);
			return (1);
		}
		pthread_mutex_lock(&(alldata->lt_eating));
		ft_current_time(&(philosopher_cur->time_last_diner));
		pthread_mutex_unlock(&(alldata->lt_eating));
		ft_smart_sleep(alldata->time_eat);
		pthread_mutex_unlock(philosopher_cur->left_fork);
		pthread_mutex_unlock(philosopher_cur->right_fork);
		pthread_mutex_lock(&(alldata->number_of_meals));
		philosopher_cur->number_dining++;
		pthread_mutex_unlock(&(alldata->number_of_meals));
		if (ft_sleeping(philosopher_cur, alldata))
			return (NULL);
		if (ft_thinking(philosopher_cur, alldata))
			return (NULL);
	}
}
