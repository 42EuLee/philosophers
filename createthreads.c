#include "philosopher.h"

t_philo	*createthreads(char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->num = ft_atoi(argv[1]);
	philo->eat_time = ft_atoi(argv[2]);
	philo->death_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	philo->eat_cycle = ft_atoi(argv[5]);
	philo->info = (t_info *)malloc(sizeof(t_info) * philo->num);
	philo->lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->num);
	philo->thread = malloc(sizeof(pthread_t) * philo->num);
	return (philo);
}
