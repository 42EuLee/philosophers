NAME 	= philo

CC		= gcc -pthread
RM		= rm -f

SRCS	= ft_atoi.c philosopher.c createthreads.c s_to_m.c

OBJS		= $(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@


test:
		./philo 5 4 3 2 1

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM)  $(NAME) $(OBJS)

re:		fclean all
		make

.PHONY: all run clean
