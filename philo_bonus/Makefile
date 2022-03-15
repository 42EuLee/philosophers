# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:24:54 by leu-lee           #+#    #+#              #
#    Updated: 2022/03/15 16:27:33 by leu-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= philo_bonus

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f

SRCS_DIR	= ./src
OBJS_DIR 	= ./obj

SRCS		= init_threads.c init_states.c ft_atoi.c s_to_m.c think_to_eat.c \
				eat_to_sleep.c ft_usleep.c print_log.c death_checker.c init_semaphores.c \
				sem_close_all.c sem_unlink_all.c free_malloc.c check_invalid.c

#SRCS_PHILO	=		$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES	= -Iincludes

all:	$(NAME)

$(NAME): $(OBJS) main.c
		# $(CC) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(CFLAGS) $(INCLUDES) main.c -o $@
		$(CC) $(CFLAGS) $(INCLUDES) main.c $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(INCLUDES) -c $< -o $@


test: re
		./philo_bonus 5 399 200 200 5

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM)  $(NAME)

re:		fclean all

.PHONY: all run clean
