#include "../philo.h"

void	destroy(t_program *data)
{
	int	i;

	i = -1;
	while (++i < data -> philos_num)
	{
		pthread_mutex_destroy(&data -> forks[i]);
		pthread_mutex_destroy(&data -> priv_lock[i]);
	}
	pthread_mutex_destroy(&data -> main_lock);
	pthread_mutex_destroy(&data -> write_message);
}

void	free_all(t_program *data)
{
	if (data -> threads)
		free(data -> threads);
	if (data -> forks)
		free(data -> forks);
	if (data -> philos)
		free(data -> philos);
	if (data -> priv_lock)
		free(data -> priv_lock);
	if (data)
		free(data);
}