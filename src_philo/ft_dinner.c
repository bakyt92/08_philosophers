#include "../philo.h"

int	ft_dinner(t_args *args)
{
	size_t	i;

	i = 0;
	if (args->number_philo == 1)
		return (1);
	ft_current_time(&(args->start_time));
	while (i < args->number_philo)
	{
		pthread_create(&(args->philosophers[i].philos), NULL, ft_simulation,
					   (void *)(&args->philosophers[i]));
		i++;
	}
	return (0);
}
