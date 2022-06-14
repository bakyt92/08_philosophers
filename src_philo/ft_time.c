#include "../philo.h"

void	ft_current_time(size_t *current)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	*current = start.tv_sec % 10000 * 1000 + start.tv_usec / 1000;
}

void	ft_smart_sleep(size_t interval)
{
	size_t begin;
	size_t end;

	ft_current_time(&begin);
	ft_current_time(&end);
	while (interval > end - begin)
	{
		ft_current_time(&end);
		usleep(100);
	}
}