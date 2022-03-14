#include "philosopher_bonus.h"

t_philo	*thread_create(t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	while (i < philo->num)
	{
		error = pthread_create(&philo->thread[i], NULL, &routine,
				&philo->info[i]);
		if (error != 0)
			printf("\n Thread can't be created: [%s]", strerror(error));
		i++;
	}
	return (philo);
}
