#include "../philo.h"

int ft_if_alive(t_args *Data)
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