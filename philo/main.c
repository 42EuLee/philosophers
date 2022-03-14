#include "philosopher.h"

int	main(int argc, char **argv)
{	
	int		i;
	t_philo	*philo;

	if (check_invalid(argc, argv) == 1)
	{
		printf("Error\n");
		return (1);
	}
	philo = init_threads(argc, argv);
	philo = init_states(philo);
	philo = thread_create(philo);
	death_checker(philo);
	i = -1;
	while (i++ < philo->num)
		pthread_join(philo->thread[i], NULL);
	i = -1;
	while (++i < philo->num)
		pthread_mutex_destroy(&philo->fork[i]);
	pthread_mutex_destroy(&philo->miniphone);
	free_malloc(philo);
	//system("leaks philo");
	return (0);
}
