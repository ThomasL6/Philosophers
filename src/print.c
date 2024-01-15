#include "../philo.h"

int	error_message(char *message)
{
	put_string(message, STDOUT_FILENO);
	put_string("\n", STDOUT_FILENO);
	return (EXIT_FAILURE);
}

int	error_message_args(t_program *data)
{
	if (data -> philos_num < 1)
		return(error_message("\033[1;32mis eating \033[0m"));
	if (data -> time_to_die <= 0)
		return(error_message("\033[1;91mTime_to_die must be greater than 0\033[0m"));
	if (data -> time_to_eat <= 0)
		return(error_message("\033[1;91mTime_to_eat must be greater than 0\033[0m"));
	if (data -> time_to_sleep <= 0)
		return(error_message("033[1;91mThe time_to_sleep must be greater than 0\033[0m"));
	return (0);
}

void	print_info(t_data *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(philo -> write_message);
	time = get_time_now() - *philo -> start_time;
	if (time >= 0 && time <= 2147483647 && alive_check(philo))
		printf("[%d] Philo: %d %s\n", (int)time, philo -> philo_id, action);
	pthread_mutex_unlock(philo -> write_message);
}
