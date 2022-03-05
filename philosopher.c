#include "philosopher.h"

t_philo	*initstates(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		if (pthread_mutex_init(&philo->lock[i], NULL) != 0)
		{
			printf("\n Mutex init has failed\n");
			return (NULL);
		}
		philo->info[i].lock = philo->lock;
		philo->info[i].id = i;
		philo->info[i].state = thinking;
		philo->info[i].ptr = philo;
		i++;
	}
	return (philo);
}

void	*handler(void *arg)
{
	static int		i;
	t_info			*info;

	info = (t_info *)arg;

	printf("%ld ",s_to_m());
	//printf("%d: philo->num\n", philo->num);
	printf("Thread %d: thinking b4 eating\n", info->id);

	if (info->state == thinking)
	{
		if (info->id == info->ptr->num - 1)
		{
			pthread_mutex_lock(&info->lock[info->id]);
			printf("has taken a fork: %d\n", info->id);
			pthread_mutex_lock(&info->lock[0]);
			// printf("pick up fork2: %d\n", 0 );
			info->state = eating;
		}
		else
		{
			pthread_mutex_lock(&info->lock[info->id]);
			printf("has taken fork: %d\n", info->id);
			pthread_mutex_lock(&info->lock[info->id + 1]);
			// printf("pick up fork2: %d\n", info->id + 1 );
			info->state = eating;
		}
	}
	if (info->state == eating)
	{
		printf("Thread %d: eating yo\n", info->id);
		usleep(1000000);
		info->state = sleeping;
		printf("Thread %d: sleeping yo\n", info->id);
		usleep(2000000);
		if (info->id == info->ptr->num - 1)
		{
			pthread_mutex_unlock(&info->lock[info->id]);
			printf("has taken fork: %d\n", info->id);
			pthread_mutex_unlock(&info->lock[0]);
			// printf("puts down fork2: %d\n", 0);
		}
		else
		{
			pthread_mutex_unlock(&info->lock[info->id]);
			printf("has taken fork: %d\n", info->id);
			pthread_mutex_unlock(&info->lock[info->id + 1]);
			// printf("puts down fork2: %d\n", info->id + 1);
		}
		//printf("Thread %d: Done\n", info->id);
		info->time_left = 0;
		info->state = thinking;
	}

	//return (NULL);
}

int	main(int argc, char **argv)
{
	int			i;
	int			error;
	t_philo		*philo;

	philo = createthreads(argv);
	philo = initstates(philo); // check for error later

	// creating philosopher threads
	i = 0;
	while (i < philo->num)
	{
	//	printf("pointer: %ld\n", info->thread[i]);
		error = pthread_create(&philo->thread[i], NULL, &handler, (void *)&philo->info[i]);
		if (error != 0)
			printf("\n Thread can't be created: [%s]", strerror(error));
		i++;
	}
	// joining philosopher threads
	i = 0;
	while (i < philo->num)
	{
		pthread_join(philo->thread[i], NULL);
		i++;
	}
	//pthread_mutex_destroy(philo->lock); // loop later free dem_locks
	return (0);
}
