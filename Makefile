NAME 	= philo

PHILO_BONUS = philo_bonus

CC		= gcc -Wall -Wextra -Werror -pthread

RM		= rm -f

SRCS	= ft_atoi.c philosopher.c init_threads.c s_to_m.c thread_create.c ft_usleep.c \
			think_to_eat.c even_num.c odd_num.c print_log.c death_checker.c free_malloc.c \
			eat_to_sleep.c init_states.c check_invalid.c

SRCS_B	= philosopher_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@

bonus: $(PHILO_BONUS)

$(PHILO_B): $(OBJS_B)
		$(CC) $(OBJS_B) -o $@


test: re
		./philo 4 400 200 200

test2: re
		./philo_bonus 4 410 200 200 1

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM)  $(NAME) $(OBJS)

re:		fclean all
		make

.PHONY: all run clean
