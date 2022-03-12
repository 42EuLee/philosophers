#include "philosopher_bonus.h"

long	s_to_m(void)
{
	struct timeval	current_time;
	long long		ms;

	gettimeofday(&current_time, NULL);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ms);
}
