#include "philosopher_bonus.h"

void	sem_unlink_all(t_philo *philo)
{
	sem_unlink(philo->semstr);
	sem_unlink(philo->deathstr);
	sem_unlink(philo->eatenstr);
	sem_unlink(philo->printstr);
}
