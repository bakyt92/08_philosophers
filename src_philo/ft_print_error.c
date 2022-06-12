#include "../philo.h"

int	ft_print_error(char *str)
{
	printf("\033[0;31m");
	printf("%s", str);
	printf("\033[0m");
	return (0);
}