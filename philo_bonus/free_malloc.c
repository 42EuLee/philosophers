#include "philosopher_bonus.h"

void	free_malloc(t_philo *philo)
{
	free(philo->info);
	free(philo->thread);
	free(philo->pid);
	free(philo->eat_thread);
	free(philo->death_thread);
	free(philo);
}
