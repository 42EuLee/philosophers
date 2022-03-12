#include "philosopher_bonus.h"

void	ft_usleep(int sleep)
{
	long long	begin;
	long long	current;

	begin = s_to_m();
	while (1)
	{
		current = s_to_m();
		if (((current - begin) * 1000) >= (long)sleep)
			break ;
		usleep(100);
	}
}
