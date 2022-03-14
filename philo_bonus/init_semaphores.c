#include "philosopher_bonus.h"

void	*init_semaphores(t_philo *philo)
{
	static int	i;

	philo->printstr = "print";
	philo->semstr = "sem";
	philo->deathstr = "death";
	philo->eatenstr = "eaten";
	sem_unlink_all(philo);
	philo->sem = sem_open("sem", O_CREAT, 0644, 0);
	philo->death = sem_open("death", O_CREAT, 0644, 0);
	philo->eaten = sem_open("eaten", O_CREAT, 0644, 0);
	philo->print = sem_open("print", O_CREAT, 0644, 1);
	i = -1;
	while (++i < philo->num)
		sem_post(philo->sem);
	return (philo);
}
