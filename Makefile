NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCES = src/arguments_check.c\
		  src/control.c\
		  src/destroy_and_free.c\
		  src/print.c\
		  src/initialize.c\
		  src/main.c\
		  src/routine.c\
		  src/time.c\
		  src/utils.c\

all:
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean: 
	@rm -rf $(NAME)

re: fclean all