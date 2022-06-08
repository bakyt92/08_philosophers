
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_Data
{
	pthread_t philos;
	int id_philosopher;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	size_t	number_dining; // проверка на количество приемов пищи
	size_t	time_last_diner; //
} t_Data;

typedef struct s_args
{
	size_t 			number_philo;
	size_t 			time_die;
	size_t 			time_eat;
	size_t 			time_sleep;
	size_t 			number_each_eat;
	pthread_mutex_t	*all_forks;
	pthread_mutex_t printing;
	size_t			start_time;
	t_Data			*philosophers;
} t_args;

int		ft_check(int argc, char **argv);
void	ft_read_args(char **argv, t_args *args);
int		ft_atoi(const char *str);
int		ft_init_data(t_args *args);
int		ft_create_forks(t_args *args);
int		ft_create_philosophers(t_args *args);
int		ft_dinner(t_args *args);

/* simulation */
void	*ft_simulation(void *args);

//void	ft_sleep(t_args *Data);
void	ft_thinking(t_args *Data);
void	ft_sleeping(t_args *Data);
void	ft_print_data(char *Text, t_args *Data);
void	ft_eating(t_args *Data);
void	ft_eating(t_args *Data);
int 	ft_cycle(t_args *Data);

/* time functions */
void	ft_current_time(size_t *current);

/*  */
int ft_if_alive(t_args *Data)
#endif
