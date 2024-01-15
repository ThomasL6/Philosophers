#include "../philo.h"

long int	get_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int mil_sec)
{
	long int	start_time;

	start_time = get_time_now();
	while ((get_time_now() - start_time) < mil_sec)
		usleep(100);
}

int	wait_threads(t_program *data)
{
	int	i;

	i = -1;
	while (++i < data -> philos_num)
		pthread_join(data -> threads[i], NULL);
	return (1);
}
