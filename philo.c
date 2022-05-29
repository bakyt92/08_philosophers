#include "philo.h"


void	*ft_philo_eat(void *Data)
{

}

int main(int argc, char **argv)
{
	pthread_t	*threads;
	t_args		*args;
	t_Data		*Data;

	if (ft_check(argc, argv))
	{
		write(2, "Wrong arguments\n", 16);
		return (0);
	}
	ft_read_args(argv, args);
	if (ft_init_data(args))
		return (1);
	return 0;
}
