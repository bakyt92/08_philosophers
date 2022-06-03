#include "../philo.h"

void	ft_current_time(size_t *current)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	*current = start.tv_sec * 1000 + start.tv_usec / 1000;
}