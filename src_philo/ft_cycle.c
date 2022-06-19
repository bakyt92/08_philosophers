/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:07:38 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../philo.h"

static int ft_take_left_fork(t_args *Data, t_Data *ph)
{
	pthread_mutex_lock(ph->left_fork);
//	pthread_mutex_lock(&(Data->printing));
	if (ft_if_alive(Data))
	{
//		pthread_mutex_unlock(&(Data->printing));
		pthread_mutex_unlock(ph->left_fork);
		return (1);
	}
	ft_print_data("%zu %zu has taken a fork\n", Data, ph);
//	pthread_mutex_unlock(&(Data->printing));
	return (0);
}

static int ft_take_right_fork(t_args *Data, t_Data *ph)
{
	pthread_mutex_lock(ph->right_fork);
//	pthread_mutex_lock(&(Data->printing));
	if (ft_if_alive(Data))
	{
//		pthread_mutex_unlock(&(Data->printing));
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		return (1);
	}
	ft_print_data("%zu %zu has taken a fork\n", Data, ph);
//	pthread_mutex_unlock(&(Data->printing));
	return (0);
}

static int ft_put_left_fork(t_args *Data, t_Data *ph)
{
	pthread_mutex_unlock(ph->left_fork);
//	ft_print_data("%zu %zu has put LEFT a fork\n", Data, ph);
	return (ft_if_alive(Data));
}

static int ft_put_right_fork(t_args *Data, t_Data *ph)
{
	pthread_mutex_unlock(ph->right_fork);
//	ft_print_data("%zu %zu has put RIGHT a fork\n", Data, ph);
	return (ft_if_alive(Data));
}

int ft_cycle(t_args *Data, t_Data *ph)
{
	if (ft_take_left_fork(Data, ph))
		return (1);
	if (ft_take_right_fork(Data, ph))
		return (1);
	if (ft_eating(Data, ph))
		return (1);
	if (ft_put_left_fork(Data, ph))
		return (1);
	if (ft_put_right_fork(Data, ph))
		return (1);
	if (ft_sleeping(Data, ph))
		return (1);
	if (ft_thinking(Data, ph))
		return (1);
	return (0);
}
 */