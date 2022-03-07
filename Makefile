NAME 	= philo

CC		= gcc -pthread
RM		= rm -f

SRCS	= ft_atoi.c philosopher.c createthreads.c s_to_m.c thread_create.c ft_usleep.c

OBJS		= $(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@


test: re
		./philo 5 400 200 200 1

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM)  $(NAME) $(OBJS)

re:		fclean all
		make

.PHONY: all run clean
