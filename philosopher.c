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
	philo->dead = 0;
	return (philo);
}

void	*handler(void *arg)
{
	static int		i;
	t_info			*info;

	info = (t_info *)arg;

	//printf("%ld ",s_to_m());
	//printf("%d: philo->num\n", philo->num);
	//printf("%d is thinking b4 eating\n", info->id);
	info->death_timer = s_to_m() + info->ptr->death_time;
	// printf("death time: %ld\n", (long)info->ptr->death_time);
	// printf("current_time: %ld\n", s_to_m());
	// printf("death_timer: %ld\n", info->death_timer);
	while (!info->ptr->dead)
	{
		if (info->state == thinking)
		{
			if (info->id == info->ptr->num - 1)
			{
				if (pthread_mutex_lock(&info->lock[info->id]) == 0)
				{
					info->right = 1;
					printf("%s%ld %d has taken a fork\n%s", GREEN, s_to_m(), info->id, NC);
				}
				if (pthread_mutex_lock(&info->lock[0]) == 0)
				{
					info->left = 1;
					printf("%s%ld %d has taken a fork\n%s", GREEN, s_to_m(), 0, NC);
					//printf("%s%ld %d has taken a fork2\n%s", GREEN, s_to_m(), 0, NC);
				}
			}
			else
			{
				if (pthread_mutex_lock(&info->lock[info->id]) == 0)
				{
					info->right = 1;
					printf("%s%ld %d has taken a fork\n%s", GREEN, s_to_m(), info->id, NC);
				}
				if (pthread_mutex_lock(&info->lock[info->id + 1]) == 0)
				{
					info->left = 1;
					printf("%s%ld %d has taken a fork\n%s", GREEN, s_to_m(), info->id, NC);
					//printf("%s%ld %d has taken a fork2\n%s", GREEN, s_to_m(), info->id, NC);
				}

			}
			if ((info->right == 1) && (info->left == 1))
			{
				info->death_timer = s_to_m() + info->ptr->death_time * 2;
				info->state = eating;
				printf("%s%ld %d is eating\n%s", YELLOW, s_to_m(), info->id, NC);
				usleep(info->ptr->eat_time);
			}
		}
		if (info->state == eating)
		{
			if (info->id == info->ptr->num - 1)
			{
				pthread_mutex_unlock(&info->lock[info->id]);
				//printf("%ld %d puts down a fork\n", s_to_m(), info->id);
				pthread_mutex_unlock(&info->lock[0]);
			}
			else
			{
				pthread_mutex_unlock(&info->lock[info->id]);
				//printf("%ld %d puts down their fork\n", s_to_m(), info->id);
				pthread_mutex_unlock(&info->lock[info->id + 1]);
			}
			info->death_timer = s_to_m() + info->ptr->death_time;
			info->state = sleeping;
			printf("%s%ld %d is sleeping\n%s", BLUE, s_to_m(), info->id, NC);
			usleep(info->ptr->sleep_time);
			//printf("%ld %d has done a cycle\n", s_to_m(), info->id);
			info->left = 0;
			info->right = 0;
			info->state = thinking;
			printf("%s%ld %d is thinking\n%s", TEAL, s_to_m(), info->id, NC);
		}
		if (s_to_m() > info->death_timer)
		{
			printf("%s%ld %d died%s\n", RED, s_to_m(), info->id, NC);
			info->ptr->dead = 1;
			break ;
		}
	}
	return (NULL);
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
		usleep(1);
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
