#include "philo.h"


void	*ft_philo_eat(void *Data)
{

}

int main(int argc, char **argv)
{
	pthread_t	*thread;
	t_args		*args;
	t_Data		*Data;

	if (ft_check(argc, argv) == 1)
	{
		write(2, "Wrong arguments\n", 16);
		return (0);
	}
	ft_read_args(argv, args);
	pthread_create(thread, NULL, &ft_philo_eat, (void *) Data);
	return 0;
}
