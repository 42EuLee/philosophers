#include "philosopher.h"

t_philo	*thread_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num)
		pthread_create(&philo->thread[i], NULL, &routine, &philo->info[i]);
	return (philo);
}
