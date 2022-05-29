
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_Data
{
	int id_philosopher;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;

} t_Data;

typedef struct s_args
{
	int 			number_philo;
	int 			time_die;
	int 			time_eat;
	int 			time_sleep;
	int 			number_each_eat;
	pthread_mutex_t	*all_forks;
	t_Data	*philosophers;
} t_args;



int		ft_check(int argc, char **argv);
void	ft_read_args(char **argv, t_args *args);
int		ft_atoi(const char *str);
int	ft_init_data(t_args *args);
int	ft_create_forks(t_args *args);

#endif
