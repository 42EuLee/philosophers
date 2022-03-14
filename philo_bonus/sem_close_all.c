#include "philosopher_bonus.h"

void	sem_close_all(t_philo *philo)
{
	static int	i;

	sem_close(philo->sem);
	sem_close(philo->death);
	while (i++ < philo->num)
		sem_post(philo->eaten);
	sem_close(philo->eaten);
	sem_close(philo->print);
}
