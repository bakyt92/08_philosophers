#include "../philo.h"

void	ft_print_data(char *Text, t_args *Data)
{
	size_t	timestamp_current;

	ft_current_time(&timestamp_current);
	timestamp_current = timestamp_current - Data->start_time;
	printf(Text, timestamp_current, Data->philosophers->id_philosopher);
}

void	ft_eating(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is sleeping\n", Data);
	usleep(Data->time_sleep * 1000);
	pthread_mutex_unlock(&(Data->printing));
}

void	ft_sleeping(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is sleeping\n", Data);
	usleep(Data->time_sleep * 1000);
	pthread_mutex_unlock(&(Data->printing));
}

void	ft_thinking(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is thinking\n", Data);
	pthread_mutex_unlock(&(Data->printing));
}

void	*ft_simulation(void *args)
{
	t_args *Data;

	Data = (t_args *)args;
	if (Data->philosophers->id_philosopher % 2 == 0)
		ft_thinking(Data);
	else
	{
		ft_thinking(Data);
		usleep(Data->time_eat * 1000);
	}
	ft_eating(Data);
	ft_sleeping(Data);
}

