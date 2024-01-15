#include "../philo.h"

int	set_check_args(t_program *data, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (error_message(("\033[1;91mWrong number of arguments\033[0m")));
	i = 1;
	while (i < argc)
	{
		if (!digit_check(argv[i]))
			return(error_message("\033[1;91mArguments has to be as digits\033[0m"));
		if (is_int(argv[i]) <= 0)
			return(error_message("\033[1;91mArguments must be greater than 0\033[0m"));
		i++;
	}
	set_arguments(data, argc, argv);
	if (error_message_args(data) == EXIT_FAILURE)
		return (free(data), EXIT_FAILURE);
	return (0);
}

void	set_arguments(t_program *data, int argc, char **argv)
{	
	data -> philos_num = ft_atoi(argv[1]);
	data -> time_to_die = ft_atoi(argv[2]);
	data -> time_to_eat = ft_atoi(argv[3]);
	data -> time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data -> eat_x_times = ft_atoi(argv[5]);
		if (argv[5] && data -> eat_x_times < 0)
			printf("\033[1;91mThe number of meals cannot be negative\033[0m\n");
	}
	else
		data -> eat_x_times = 0;
}
