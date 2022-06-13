#include "../philo.h"

void	ft_print_data(char *Text, t_args *Data)
{
	size_t	timestamp_current;

	ft_current_time(&timestamp_current);
	timestamp_current = timestamp_current - Data->start_time;
	printf(Text, timestamp_current, Data->philosophers->id_philosopher);
}

int	ft_sleeping(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is sleeping\n", Data);
	pthread_mutex_unlock(&(Data->printing));
	usleep(Data->time_sleep * 1000);
}

int	ft_thinking(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is thinking\n", Data);
	pthread_mutex_unlock(&(Data->printing));
	return (0);
}

int	ft_eating(t_args *Data)
{
	size_t	timestamp_current;

	pthread_mutex_lock(&(Data->printing));
	pthread_mutex_lock(&(Data->number_of_meals));
	ft_print_data("%zu %zu is eating\n", Data);
	ft_current_time(&timestamp_current);
	Data->philosophers[Data->philosophers->id_philosopher].time_last_diner =
			timestamp_current;
	Data->philosophers[Data->philosophers->id_philosopher].number_dining++;
	pthread_mutex_unlock(&(Data->number_of_meals));
	pthread_mutex_unlock(&(Data->printing));
	usleep(Data->time_eat * 1000);
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
	while (1)
	{
		if (!ft_cycle(Data))
			break ;
	}
	return(NULL);
}

