/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:01 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/21 00:16:49 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_print_data(char *text, t_Data *philosopher_cur, t_args *alldata)
{
	long long	time_now;

	if (ft_if_alive(alldata))
	{
//		printf("Philo %zu exited \n", philosopher_cur->id_philosopher);
		return (1);
	}
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

static int	ft_thinking(t_Data *philosopher_cur, t_args *alldata)
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
//	printf("#######START TIME %lld #######\n", philosopher_cur->args1->start_time);
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
//		printf("%zu Left FORK %p\n", philosopher_cur->id_philosopher, philosopher_cur->left_fork);
//		printf("%zu Right FORK %p\n", philosopher_cur->id_philosopher, philosopher_cur->right_fork);
		if (ft_if_alive(alldata))
			return (NULL);
		pthread_mutex_lock(philosopher_cur->left_fork);
		if (ft_print_data("%lld %zu has taken a fork\n",
				philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			return (NULL);
		}
		if (ft_if_alive(alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			return (NULL);
		}
//		printf("Left Fork %p\n", philosopher_cur->left_fork);
		pthread_mutex_lock(philosopher_cur->right_fork);
		if (ft_print_data("%lld %zu has taken a fork\n",
				philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			pthread_mutex_unlock(philosopher_cur->right_fork);
			return (NULL);
		}
		if (ft_print_data("%lld %zu is eating\n", philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			pthread_mutex_unlock(philosopher_cur->right_fork);
			return (NULL);
		}
		pthread_mutex_lock(&(alldata->lt_eating));
		ft_current_time(&(philosopher_cur->time_last_diner));
		pthread_mutex_unlock(&(alldata->lt_eating));
		ft_smart_sleep(alldata->time_eat);
		pthread_mutex_unlock(philosopher_cur->left_fork);
		pthread_mutex_unlock(philosopher_cur->right_fork);
//		pthread_mutex_lock(&(alldata->lt_eating));
//		ft_current_time(&(philosopher_cur->time_last_diner));
//		pthread_mutex_unlock(&(alldata->lt_eating));
		pthread_mutex_lock(&(alldata->number_of_meals));
		philosopher_cur->number_dining++;
		pthread_mutex_unlock(&(alldata->number_of_meals));
		if (ft_sleeping(philosopher_cur, alldata))
			return (NULL);
		if (ft_thinking(philosopher_cur, alldata))
			return (NULL);
//		printf("Philo stay alive %zu \n", philosopher_cur->id_philosopher);
	}
}