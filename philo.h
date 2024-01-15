
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				ate_x_times;
	int				*already_ate_max;
	int				stop;
	long int		last_meal_time;
	long int		*start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	*write_message;
}				t_data;

typedef struct s_program
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				already_ate_max;
	long int		start_time;
	t_data	*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_message;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	*priv_lock;
}				t_program;


int				set_check_args(t_program *data, int argc, char **argv);
int				meal_check(t_program *data, t_data *philo);
int				error_message(char *message);
int				error_message_args(t_program *data);
int				init_all(t_program *data);
int				init_mutex(t_program *data);
int				meal(t_data	*philo);
int				wait_threads(t_program *data);
int				alive_check(t_data *philo);
int				init_threads(t_program *data);
int				digit_check(char *c);
int				is_int(char *str);
int				ft_atoi(char *str);
long int		get_time_now(void);
void			update_meal_status(t_data *philo);
void			set_arguments(t_program *data, int argc, char **argv);
void			control(t_program *data, t_data *philo);
void			destroy(t_program *data);
void			free_all(t_program *data);
void			print_info(t_data *philo, char *action);
void			init_philo(t_program *data, t_data *philo);
void			*philo_routine(void *arg);
void			ft_usleep(int mil_sec);
void			put_char(char c, int fd);
void			put_string(char *s, int fd);

#endif