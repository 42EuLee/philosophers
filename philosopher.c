#include "philosopher.h"

void	*handler(void *arg)
{
	t_info			*info;

	info = (t_info *)arg;
	print_log(info);
	if (odd_num(info->id) == 1)
		ft_usleep(60);
	while (!info->ptr->dead && info->ptr->eaten < info->ptr->num)
	{
		think_to_eat(info);
		eat_to_sleep(info);
	}
	return (NULL);
}

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
	//pthread_mutex_destroy(philo->lock); // loop later free dem_locks
	free_malloc(philo);
	//system("leaks philo");
	return (0);
}
