#include "philo.h"

int main(int argc, char **argv)
{
	pthread_t	*thread;
	t_args		*args;

	if (ft_check(argc, argv) == 1)
	{
		write(2, "Wrong arguments\n", 16);
		return (0);
	}
	ft_read_args(argv, args);

	return 0;
}
