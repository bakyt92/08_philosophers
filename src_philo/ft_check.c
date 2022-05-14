#include "../philo.h"

int ft_check(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 5 || argc != 6)
		return (1);
	while(argv[i++])
	{
		if (ft_itoa(i) < 0)
			return (1);
	}
	return (0);
}