/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:06:52 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:08:34 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_current_time(long long *current)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	*current = start.tv_sec % 1000000 * 1000 + start.tv_usec / 1000;
}

void	ft_smart_sleep(long long interval)
{
	long long	begin;
	long long	end;

	ft_current_time(&begin);
	ft_current_time(&end);
	while (interval > end - begin)
	{
		ft_current_time(&end);
		usleep(100);
	}
}
