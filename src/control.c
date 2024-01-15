#include "../philo.h"

int	meal_check(t_program *data, t_data *philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data -> main_lock);
	if (data -> already_ate_max == data -> philos_num)
	{
		printf("%s\n", ("\033[0;36mphilosophers has finished their meals \033[0m"));
		while (++i < data -> philos_num)
			philo[i].stop = 1;
		pthread_mutex_unlock(&data -> main_lock);
		return (-1);
	}
	pthread_mutex_unlock(&data -> main_lock);
	return (0);
}

void	control(t_program *data, t_data *philo)
{
	int				i;

	i = -1;
	while (++i < data -> philos_num)
	{
		pthread_mutex_lock(&data -> priv_lock[i]);
		if (get_time_now() - philo[i].last_meal_time >= data -> time_to_die)
		{
			pthread_mutex_unlock(&data -> priv_lock[i]);
			pthread_mutex_lock(&data -> main_lock);
			printf("[%d] Philo: %d %s\n", \
				(int)(get_time_now() - data -> start_time), i + 1,
				("\033[1;91mdied \033[0m"));
			i = -1;
			while (++i < data -> philos_num)
				philo[i].stop = 1;
			pthread_mutex_unlock(&data -> main_lock);
			return ;
		}
		pthread_mutex_unlock(&data -> priv_lock[i]);
		if (meal_check(data, philo) == -1)
			return ;
		if (i + 1 == data -> philos_num)
			i = -1;
	}
}
