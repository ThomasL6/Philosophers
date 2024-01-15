#include "../philo.h"

int	main(int argc, char **argv)
{
	t_program	*data;

	data = malloc(sizeof(t_program));
	if (set_check_args(data, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all(data) == -1)
		return (EXIT_FAILURE);
	control(data, data -> philos);
	wait_threads(data);
	destroy(data);
	free_all(data);
}
