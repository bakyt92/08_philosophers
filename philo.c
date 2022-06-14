#include "philo.h"

int ft_end_dinner(t_args *args)
{
	size_t i;

	i = 0;
	while (i < args->number_philo)
	{
		pthread_detach(args->philosophers[i].philos);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
//	pthread_t	*threads;
	t_args		*args;
//	t_Data		*Data;

	if (ft_check(argc, argv))
	{
		ft_print_error("Wrong arguments\n");
		return (0);
	}
	args = malloc(sizeof(t_args));
	ft_read_args(argv, args);
	if (ft_init_data(args))
		return (1);
//	printf("checkpoint 1 %zu\n", args->philosophers[1].id_philosopher);
//	printf("checkpoint 2 %zu\n", args->number_philo);
	ft_dinner(args);
	ft_check_living(args);
	ft_end_dinner(args);
	return (0);
}
