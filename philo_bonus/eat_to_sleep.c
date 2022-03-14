#include "philosopher_bonus.h"

void	eat_to_sleep(t_info *info)
{
	if (info->state == eating)
	{
		sem_post(info->ptr->sem);
		sem_post(info->ptr->sem);
		if (info->times_eat == info->ptr->eat_cycle)
		{
			sem_post(info->ptr->eaten);
			//system("leaks philo_bonus");
			exit(0);
		}
		info->state = sleeping;
		print_log(info);
		ft_usleep(info->ptr->sleep_time);
		info->state = thinking;
		usleep(50);
	}
}
