/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:07:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:07:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int ft_isdigit(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ' || str[i] == '+' || \
		(str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

int ft_check(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		return (1);
	}
	while(argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (1);
		if (ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}