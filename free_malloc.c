#include "philosopher.h"

void	free_malloc(t_philo *philo)
{
	free(philo->info);
	free(philo->fork);
	free(philo->thread);
	free(philo);
}
