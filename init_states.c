#include "philosopher.h"

t_philo	*init_states(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
		{
			printf("\n Mutex init has failed\n");
			return (NULL);
		}
		philo->info[i].id = i;
		philo->info[i].state = thinking;
		philo->info[i].ptr = philo;
		philo->info[i].times_eat = 0;
		philo->info[i].death_timer = s_to_m() + philo->death_time;
		i++;
	}
	philo->dead = 0;
	return (philo);
}
