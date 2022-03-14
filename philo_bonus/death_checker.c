#include "philosopher_bonus.h"

void	*death_check(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	sem_wait(info->ptr->death);
	sem_post(info->ptr->death);
	//system("leaks philo_bonus");
	exit(0);
}

void	*death_checker(void *arg)
{
	t_info		*info;
	static int	i;

	info = arg;
	pthread_create(info->ptr->death_thread, NULL, death_check, info);
	while (!(info->ptr->dead))
	{
		if (s_to_m() > info->death_timer)
		{
			sem_wait(info->ptr->print);
			info->ptr->dead = 1;
			while (i++ < info->ptr->num)
				sem_post(info->ptr->death);
			printf("%s%ld %d died%s\n", RED, s_to_m(), info->id, NC);
		}
		ft_usleep(1);
	}
	return (NULL);
}
