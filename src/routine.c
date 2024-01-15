#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_data	*philo;

	philo = (t_data *)arg;
	if (philo -> philo_id % 2 == 0)
		ft_usleep(philo -> time_to_eat * 0.9);
	while (alive_check(philo))
	{
		if (meal(philo) == -1)
			return (NULL);
		if (!alive_check(philo))
			return (NULL);
		print_info(philo, ("\033[1;33mis sleeping \033[0m"));
		ft_usleep(philo -> time_to_sleep);
		print_info(philo, ("\033[1;36mis thinking \033[0m"));
	}
	return (NULL);
}

void	update_meal_status(t_data *philo)
{
	pthread_mutex_lock(philo -> priv_lock);
	philo -> last_meal_time = get_time_now();
	pthread_mutex_unlock(philo -> priv_lock);
	if (philo -> eat_x_times != 0)
	{
		if (++philo -> ate_x_times == philo -> eat_x_times)
		{
			pthread_mutex_lock(philo -> main_lock);
			*philo -> already_ate_max += 1;
			pthread_mutex_unlock(philo -> main_lock);
		}
	}
}

int	meal(t_data	*philo)
{
	if (!alive_check(philo))
		return (-1);
	pthread_mutex_lock(philo -> l_fork);
	print_info(philo,("\033[1;35mhas taken l fork \033[0m"));
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> l_fork), -1);
	if (philo -> r_fork == NULL)
		return (pthread_mutex_unlock(philo -> l_fork),
			ft_usleep(philo -> time_to_die * 1.1), -1);
	pthread_mutex_lock(philo -> r_fork);
	print_info(philo, ("\033[1;35mhas taken r fork \033[0m"));
	print_info(philo, ("\033[1;32mis eating \033[0m"));
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> l_fork),
			pthread_mutex_unlock(philo -> r_fork), -1);
	update_meal_status(philo);
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> l_fork),
			pthread_mutex_unlock(philo -> r_fork), -1);
	ft_usleep(philo -> time_to_eat);
	pthread_mutex_unlock(philo -> r_fork);
	pthread_mutex_unlock(philo -> l_fork);
	return (0);
}

int	alive_check(t_data *philo)
{
	pthread_mutex_lock(philo -> main_lock);
	if (!philo -> stop)
	{
		pthread_mutex_unlock(philo -> main_lock);
		return (1);
	}
	pthread_mutex_unlock(philo -> main_lock);
	return (0);
}
