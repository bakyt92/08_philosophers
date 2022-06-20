/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:24 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/21 00:26:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_if_alive(t_args *Data)
{
	pthread_mutex_lock(&(Data->alive));
	if (Data->status_live == 1)
	{
		pthread_mutex_unlock(&(Data->alive));
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&(Data->alive));
		return (1);
	}
}
