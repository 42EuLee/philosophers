NAME 	= philo

PHILO_BONUS = philo_bonus

CC		= gcc -Wall -Wextra -Werror -pthread

RM		= rm -f

SRCS	= ft_atoi.c philosopher.c init_threads.c s_to_m.c thread_create.c ft_usleep.c \
			think_to_eat.c even_num.c odd_num.c print_log.c death_checker.c free_malloc.c \
			eat_to_sleep.c init_states.c check_invalid.c

SRCS_B	= philosopher_bonus.c init_threads.c init_states.c ft_atoi.c s_to_m.c think_to_eat.c \
			even_num.c odd_num.c eat_to_sleep.c ft_usleep.c print_log.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)


all:	$(PHILO_BONUS)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@

bonus: $(PHILO_BONUS)

$(PHILO_BONUS): $(OBJS_B)
		$(CC) $(OBJS_B) -o $@


test: re
		./philo 50 410 200 200

test2: re
		./philo_bonus 4 410 200 200 1

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM)  $(NAME) $(PHILO_BONUS) $(OBJS) $(OBJS_B)

re:		fclean all
		make bonus

.PHONY: all run clean
