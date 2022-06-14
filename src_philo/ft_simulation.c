#include "../philo.h"

void	ft_print_data(char *Text, t_args *Data, t_Data *ph)
{
	size_t	timestamp_current;

	ft_current_time(&timestamp_current);
	timestamp_current = timestamp_current - Data->start_time;
	printf(Text, timestamp_current, ph->id_philosopher);
}

int	ft_sleeping(t_args *Data, t_Data *ph)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is sleeping\n", Data, ph);
	pthread_mutex_unlock(&(Data->printing));
	ft_smart_sleep(Data->time_sleep);
	return (ft_if_alive(Data));
}

int	ft_thinking(t_args *Data, t_Data *ph)
{
	pthread_mutex_lock(&(Data->printing));
	ft_print_data("%zu %zu is thinking\n", Data, ph);
	pthread_mutex_unlock(&(Data->printing));
	return (ft_if_alive(Data));
}

int	ft_eating(t_args *Data, t_Data *ph)
{
	size_t	timestamp_current;

//	printf("EDA #1\n");
	pthread_mutex_lock(&(Data->printing));
	pthread_mutex_lock(&(Data->number_of_meals));
	ft_print_data("%zu %zu is eating\n", Data, ph);
	ft_current_time(&timestamp_current);
	ph->time_last_diner = timestamp_current;
	ph->number_dining++;
	pthread_mutex_unlock(&(Data->number_of_meals));
	pthread_mutex_unlock(&(Data->printing));
	ft_smart_sleep(Data->time_eat);
	return (ft_if_alive(Data));
}

void	*ft_simulation(void *cur_philosopher)
{
	t_Data *philosopher_cur;
	t_args *allData;

	philosopher_cur = (t_Data *)cur_philosopher;
	allData = philosopher_cur->args1;
//	printf("Test %zu\n", philosopher_cur->id_philosopher);
	if (philosopher_cur->id_philosopher % 2 == 0)
		ft_thinking(allData, philosopher_cur);
	else
	{
		ft_thinking(allData,philosopher_cur);
		ft_smart_sleep(allData->time_eat);
	}
	while (1)
	{
//		printf("check_1\n");
		if (ft_cycle(allData, philosopher_cur))
			break ;
	}
	return(NULL);
}

