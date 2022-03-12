#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include "styling.h"
# include <semaphore.h>

enum e_status{ eating, sleeping, thinking, forking};

typedef struct s_philo	t_philo;

typedef struct s_info
{
	enum e_status	state;
	int				id;
	t_philo			*ptr;
	long			time_count;
	long			death_timer;
	int				times_eat;
	int				left;
	int				right;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_cycle;
	int				counter;
	int				dead;
	int				eaten;
	t_info			*info;
	sem_t			*sem;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	miniphone;
}	t_philo;

int		ft_atoi(const char *str);
int		main(int argc, char **argv);
t_philo	*init_threads(int argc, char **argv);
t_philo	*init_states(t_philo *philo);
long	s_to_m(void);
void	*handler(void *arg);
t_philo	*thread_create(t_philo *philo);
void	ft_usleep(int sleep);
int		odd_num(int num);
int		even_num(int num);
void	print_log(t_info *info);
void	death_checker(t_philo *philo);
void	free_malloc(t_philo *philo);
int		check_invalid(int argc, char **argv);
void	think_to_eat(t_info *info);
void	eat_to_sleep(t_info *info);
t_philo	*thread_create(t_philo *philo);

#endif