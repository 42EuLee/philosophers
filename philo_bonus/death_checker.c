#include "philosopher_bonus.h"

void	*death_check(void *arg)
{
	t_info *info;
	info = arg;

	//printf("started\n");
	sem_wait(info->ptr->death);
	sem_post(info->ptr->death);
	//printf("%d died\n", getpid());
	exit(0);
}

void	*death_checker(void *arg)
{
	t_info		*info;
	static		int i;
	pthread_t	*death_thread;

	death_thread = malloc(sizeof(pthread_t));
	info = arg;
	pthread_create(death_thread, NULL, death_check, info);
	// sem_post(info->ptr->death);
	// sem_post(info->ptr->death);
	// if (printf("sem wait returns%d\n", sem_wait(info->ptr->death) == 1))
	// 	printf("hi\n");
	while (!(info->ptr->dead))
	{
		if (s_to_m() > info->death_timer)
		{
			info->ptr->dead = 1;
			while (i++ < info->ptr->num)
				sem_post(info->ptr->death); //posting death semaphore
			print_log(info);
		}
		ft_usleep(1);
	}
	return (NULL);
}
