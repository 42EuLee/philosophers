#include "philosopher.h"

t_philo	*death_timestart(t_philo *philo)
{
	static int	i;

	while (i < philo->num)
	{
		philo->info[i].death_timer = s_to_m() + philo->death_time;
		//printf("hi");
		i++;
	}
	return (philo);	
}

t_philo	*thread_create(t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	while (i < philo->num)
	{
		//philo = death_timestart(philo);
		printf("%s%ld %d is thinking\n%s", TEAL, s_to_m(), philo->info[i].id, NC);
		philo->info[i].state = thinking;
		error = pthread_create(&philo->thread[i], NULL, &handler,
				(void *)&philo->info[i]);	
		if (error != 0)
			printf("\n Thread can't be created: [%s]", strerror(error));
		i++;
		//ft_usleep(1); 
	}
	return (philo);
}
