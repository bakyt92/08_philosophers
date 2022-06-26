/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:55:54 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/19 17:06:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_Data
{
	pthread_t		philos;
	size_t			id_philosopher;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	size_t			number_dining;
	long long		time_last_diner;
	struct s_args	*args1;
}	t_Data;

typedef struct s_args
{
	size_t			number_philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	size_t			number_each_eat;
	int				status_live;
	long long		start_time;
	long long		death_time;
	pthread_mutex_t	*all_forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	number_of_meals;
	pthread_mutex_t	alive;
	pthread_mutex_t	lt_eating;
	t_Data			*philosophers;
}	t_args;

/* START */
int		ft_check(int argc, char **argv);
void	ft_read_args(char **argv, t_args *args);
int		ft_atoi(const char *str);

/* init data */
int		ft_init_data(t_args *args);
int		ft_create_forks(t_args *args);
int		ft_create_philosophers(t_args *args);
int		ft_create_mutex(t_args *args);

/* simulation */

int		ft_dinner(t_args *args);
void	*ft_simulation(void *args);
int		ft_thinking(t_Data *philosopher_cur, t_args *alldata);

/* PRINT DATA */
int	ft_print_data(char *text, t_Data *philosopher_cur, t_args *alldata);
/*
//void	ft_sleep(t_args *Data);
int		ft_thinking(t_args *Data, t_Data *ph);
int		ft_sleeping(t_args *Data, t_Data *ph);
void	ft_print_data(char *Text, t_args *Data, t_Data *ph);
int		ft_eating(t_args *Data, t_Data *ph);
int		ft_cycle(t_args *Data, t_Data *ph);
 */

/* time functions */
void	ft_current_time(long long *current);
void	ft_smart_sleep(long long interval);

/* check if alive */
int		ft_if_alive(t_args *Data);

/* Monitoring */
void	*ft_check_living(void *args);
//int		ft_check_living(t_args *args);
int		ft_living_script(t_args *args);
int		ft_check_nbr_eating(t_args *args);

/*ft_error */
int		ft_print_error(char *str);
#endif
