/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:01 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:11:12 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../philo.h"

// переделать принт дата - проверка на живы ли философы, поставить 2 мьютекса
// на printing + alive. Контролировать количество мютексов
// некоторые мьютексы ускоряют процесс
void    ft_print_data(char *Text, t_args *Data, t_Data *ph)
{
	size_t	timestamp_current;

	ft_current_time(&timestamp_current);
	timestamp_current = timestamp_current - Data->start_time;
	pthread_mutex_lock(&(Data->printing));
	printf(Text, timestamp_current, ph->id_philosopher);
	pthread_mutex_unlock(&(Data->printing));
}

int	ft_sleeping(t_args *Data, t_Data *ph)
{
//	pthread_mutex_lock(&(Data->printing));
	if (ft_if_alive(Data))
	{
//		pthread_mutex_unlock(&(Data->printing));
		return (1);
	}
	ft_print_data("%zu %zu is sleeping\n", Data, ph);
//	pthread_mutex_unlock(&(Data->printing));
	ft_smart_sleep(Data->time_sleep);
	return (0);
}

int	ft_thinking(t_args *Data, t_Data *ph)
{
//	pthread_mutex_lock(&(Data->printing));
	if (ft_if_alive(Data))
	{
//		pthread_mutex_unlock(&(Data->printing));
		return (1);
	}
	ft_print_data("%zu %zu is thinking\n", Data, ph);
//	pthread_mutex_unlock(&(Data->printing));
	return (0);
}

int	ft_eating(t_args *Data, t_Data *ph)
{
	size_t	timestamp_current;

//	pthread_mutex_lock(&(Data->printing));
	pthread_mutex_lock(&(Data->number_of_meals));
	pthread_mutex_lock(&(Data->lt_eating));
	if (ft_if_alive(Data))
	{
		pthread_mutex_unlock(&(Data->lt_eating));
		pthread_mutex_unlock(&(Data->number_of_meals));
//		pthread_mutex_unlock(&(Data->printing));
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		return (1);
	}
	ft_print_data("%zu %zu is eating\n", Data, ph);
//	pthread_mutex_unlock(&(Data->printing));
	pthread_mutex_lock(&(Data->lt_eating));
	ft_current_time(&timestamp_current);
	ph->time_last_diner = timestamp_current;
	pthread_mutex_unlock(&(Data->lt_eating));
	ft_smart_sleep(Data->time_eat);
	pthread_mutex_lock(&(Data->number_of_meals));
	ph->number_dining++;
	pthread_mutex_unlock(&(Data->number_of_meals));
	pthread_mutex_unlock(&(Data->lt_eating));
	pthread_mutex_unlock(&(Data->number_of_meals));
//	pthread_mutex_unlock(&(Data->printing));
	ft_smart_sleep(Data->time_eat);
	return (0);
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
		ft_thinking(alldata, philosopher_cur);
	else
	{
		ft_thinking(alldata, philosopher_cur);
		ft_smart_sleep(alldata->time_eat);
	}
	while (1)
	{
		if (ft_cycle(alldata, philosopher_cur))
			return (NULL);
//			break ;
	}
	return (NULL);
}
*/
#include "../philo.h"

int	ft_print_data(char *text, t_Data *philosopher_cur, t_args *alldata)
{
	size_t	time_now;

	if (ft_if_alive(alldata))
	{
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
	if (ft_print_data("%zu %zu is thinking\n", philosopher_cur, alldata))
		return (1);
	else
		return (0);
}

static int	ft_sleeping(t_Data *philosopher_cur, t_args *alldata)
{
	if (ft_print_data("%zu %zu is sleeping\n", philosopher_cur, alldata))
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
	while(1)
	{
		pthread_mutex_lock(philosopher_cur->left_fork);
		if (ft_print_data("%zu %zu has taken a fork\n", philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			return (NULL);
		}
		pthread_mutex_lock(philosopher_cur->right_fork);
		if (ft_print_data("%zu %zu has taken a fork\n", philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			pthread_mutex_unlock(philosopher_cur->right_fork);
			return (NULL);
		}
		if (ft_print_data("%zu %zu is eating\n", philosopher_cur, alldata))
		{
			pthread_mutex_unlock(philosopher_cur->left_fork);
			pthread_mutex_unlock(philosopher_cur->right_fork);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher_cur->left_fork);
		pthread_mutex_unlock(philosopher_cur->right_fork);
		pthread_mutex_lock(&(alldata->lt_eating));
		ft_current_time(&(philosopher_cur->time_last_diner));
		pthread_mutex_unlock(&(alldata->lt_eating));
		pthread_mutex_lock(&(alldata->number_of_meals));
		philosopher_cur->number_dining++;
		pthread_mutex_unlock(&(alldata->number_of_meals));
		ft_smart_sleep(alldata->time_eat);
		if (ft_sleeping(philosopher_cur, alldata))
			return (NULL);
		if (ft_thinking(philosopher_cur, alldata))
			return (NULL);
	}
}