# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:23:18 by leu-lee           #+#    #+#              #
#    Updated: 2022/03/15 15:41:40 by leu-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= philo

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread -fsanitize=address
RM			= rm -f

SRCS_DIR	= ./src
OBJS_DIR 	= ./obj

SRCS		= ft_atoi.c routine.c init_threads.c s_to_m.c thread_create.c ft_usleep.c \
				think_to_eat.c even_num.c odd_num.c print_log.c death_checker.c free_malloc.c \
				eat_to_sleep.c init_states.c check_invalid.c

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES	= -Iincludes

all:	$(NAME)

$(NAME): $(OBJS) main.c
		$(CC) $(CFLAGS) $(INCLUDES) main.c $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(INCLUDES) -c $< -o $@

test: re
		./philo 4 400 200 400 5

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all run clean
