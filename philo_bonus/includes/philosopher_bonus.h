/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:25:01 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 12:01:32 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include "styling.h"

enum e_status{ eating, sleeping, thinking, forking};

typedef struct s_philo	t_philo;

typedef struct s_info
{
	enum e_status	state;
	int				id;
	int				times_eat;
	long			death_timer;
	t_philo			*ptr;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_cycle;
	int				dead;
	char			*deathstr;
	char			*eatenstr;
	char			*printstr;
	char			*semstr;
	pid_t			*pid;
	sem_t			*death;
	sem_t			*eaten;
	sem_t			*sem;
	sem_t			*print;
	pthread_t		*eat_thread;
	pthread_t		*death_thread;
	pthread_t		*thread;
	pthread_mutex_t	miniphone;
	t_info			*info;
}	t_philo;

int		main(int argc, char **argv);
int		check_invalid(int argc, char **argv);
int		ft_atoi(const char *str);
int		even_num(int num);
int		odd_num(int num);
void	*death_checker(void *arg);
void	free_malloc(t_philo *philo);
void	ft_usleep(int sleep);
void	eat_to_sleep(t_info *info);
void	*routine(void *arg);
void	*init_semaphores(t_philo *philo);
void	print_log(t_info *info);
void	think_to_eat(t_info *info);
void	sem_close_all(t_philo *philo);
void	sem_unlink_all(t_philo *philo);
long	s_to_m(void);
t_philo	*init_threads(int argc, char **argv);
t_philo	*init_states(t_philo *philo);
t_philo	*thread_create(t_philo *philo);
t_philo	*thread_create(t_philo *philo);

#endif