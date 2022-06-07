#include "../philo.h"

static int ft_take_left_fork(t_args *Data)
{
	if (pthread_mutex_lock(&(Data->philosophers[Data->number_philo].left_fork)))


	return (ft_if_alive(Data));
}

static int ft_take_right_fork(t_args *Data)
{

	return (ft_if_alive(Data));
}

int ft_cycle(t_args *Data)
{
	if (ft_take_left_fork(Data))
		return (1);
	if (ft_take_right_fork(Data))
		return (1);

}