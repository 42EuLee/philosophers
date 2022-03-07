
#include <philosopher.h>

void	death_checker(t_philo *philo)
{
	while (philo->dead = 0)
	{
		printf("%s%ld %d died%s\n", RED, s_to_m(), philo->info->id, NC);
		philo->dead = 1;
	}
}