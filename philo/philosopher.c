#include "philosopher.h"

void	*routine(void *arg)
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
