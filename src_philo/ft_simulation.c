#include "../philo.h"

void	ft_sleep(t_args *Data)
{
	usleep(Data->time_eat * 1000);
}

void	ft_thinking(t_args *Data)
{
	pthread_mutex_lock(&(Data->printing));
	printf("%zu %zu is thinking\n", Data->philosophers->id_philosopher);
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
		ft_sleep(Data);
	}
	ft_eating(Data);
	ft_sleeping(Data);
}

