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

typedef enum { eating, sleeping, thinking, die } status;

typedef struct s_philo t_philo;

typedef struct s_info
{
	status		state; //change state 0 -> eat, 1 -> sleep , 2 -> think(w
	int	id;
	t_philo *ptr;
	long	time_count;
	long	death_timer;
	int		times_eat;
	int		left;
	int		right;
	pthread_mutex_t *lock;
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
	t_info			*info;
	pthread_t		*thread;
	pthread_mutex_t	*lock;
}	t_philo;

int		ft_atoi(const char *str);
int		main(int argc, char **argv);
t_philo	*createthreads(char **argv);
long	s_to_m(void);
void	*handler(void *arg);
t_philo	*thread_create(t_philo *philo);
void	ft_usleep(int sleep);

#endif