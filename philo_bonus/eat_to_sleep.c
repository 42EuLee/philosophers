#include "philosopher_bonus.h"

void	eat_to_sleep(t_info *info)
{
	if (info->state == eating)
	{
		// pthread_mutex_unlock(&info->ptr->fork[info->id]);
		// pthread_mutex_unlock(&info->ptr->fork[(info->id + 1) % info->ptr->num]);
		
		if (!info->ptr->dead)
			info->state = sleeping;
		print_log(info);
		ft_usleep(info->ptr->sleep_time);
		sem_post(info->ptr->sem);
		sem_post(info->ptr->sem);
		if (!info->ptr->dead)
			info->state = thinking;
		print_log(info);
	}
}
