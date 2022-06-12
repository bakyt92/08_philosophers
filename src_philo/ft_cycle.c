#include "../philo.h"

static int ft_take_left_fork(t_args *Data)
{
	if (pthread_mutex_lock(Data->philosophers[Data->number_philo].left_fork))
		return (ft_print_error("mutex lock error\n"));
	ft_print_data("%zu %zu has taken a fork\n", Data);
	return (ft_if_alive(Data));
}

static int ft_take_right_fork(t_args *Data)
{
	if (pthread_mutex_lock(Data->philosophers[Data->number_philo].right_fork))
		return (ft_print_error("mutex lock error\n"));
	ft_print_data("%zu %zu has taken a fork\n", Data);
	return (ft_if_alive(Data));
}

static int ft_put_left_fork(t_args *Data)
{
	if (pthread_mutex_lock(Data->philosophers[Data->number_philo].left_fork))
		return (ft_print_error("mutex unlock error\n"));
	return (ft_if_alive(Data));
}

static int ft_put_right_fork(t_args *Data)
{
	if (pthread_mutex_lock(Data->philosophers[Data->number_philo].right_fork))
		return (ft_print_error("mutex unlock error\n"));
	return (ft_if_alive(Data));
}

int ft_cycle(t_args *Data)
{
	if (ft_take_left_fork(Data))
		return (1);
	if (ft_take_right_fork(Data))
		return (1);
	if (ft_eating(Data))
		return (1);
	if (ft_put_left_fork(Data))
		return (1);
	if (ft_put_right_fork(Data))
		return (1);
	if (ft_sleeping(Data))
		return (1);
	if (ft_thinking(Data))
		return (1);
	return (0);
}