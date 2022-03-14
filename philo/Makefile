NAME 	= philo

CC		= gcc -Wall -Wextra -Werror -pthread

RM		= rm -f

SRCS	= ft_atoi.c routine.c init_threads.c s_to_m.c thread_create.c ft_usleep.c \
			think_to_eat.c even_num.c odd_num.c print_log.c death_checker.c free_malloc.c \
			eat_to_sleep.c init_states.c check_invalid.c main.c


OBJS	= $(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@


test: re
		./philo 2 310 200 100

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM)  $(NAME) $(OBJS)

re:		fclean all
		make

.PHONY: all run clean
