#include "philosopher_bonus.h"

// void	*even_philo(t_info *philo)
// {
// 	if (!(philo->dead) && (even_num(info->id) == 1))
// 	{
// 		if ((pthread_mutex_lock(&info->ptr->fork[info->id]) == 0))
// 		{
// 			info->right = 1; // right fork
// 			print_log(info);
// 		}
// 		if (info->ptr->num == 1)
// 			return (NULL);
// 		if ((pthread_mutex_lock(&info->ptr->fork[(info->id + 1)
// 						% info->ptr->num]) == 0) && (info->right == 1))
// 		{
// 			info->left = 1; // left fork
// 			print_log(info);
// 		}
// 	}
// 	return (NULL);
// }

// void	*odd_philo(t_info *philo)
// {
// 	if (!(info->ptr->dead) && (odd_num(info->id) == 1))
// 	{
// 		if (pthread_mutex_lock(&info->ptr->fork[(info->id + 1)
// 					% info->ptr->num]) == 0)
// 		{
// 			info->left = 1; // left fork
// 			print_log(info);
// 		}
// 		if (info->ptr->num == 1)
// 			return (NULL);
// 		if ((pthread_mutex_lock(&info->ptr->fork[info->id]) == 0)
// 			&& (info->left == 1))
// 		{
// 			info->right = 1; // right fork
// 			print_log(info);
// 		}
// 	}
// 	return (NULL);
// }
 
// void	think_to_eat(t_philo *philo)
// {
// 	if (!(philo->dead) && (philo->info->state == thinking))
// 	{
// 		philo->info->state = forking;
// 		//odd_philo(philo);
// 		//even_philo(philo);
// 		// if ((info->right == 1) && (info->left == 1)) // should be semaphore
// 		{
// 			sem_wait(philo->sem);
// 			print_log(philo->info);
// 			sem_wait(philo->sem);
// 			print_log(philo->info);
// 			philo->info->death_timer = s_to_m() + philo->death_time;
// 			philo->info->state = eating;
// 			philo->info->times_eat++;
// 			print_log(philo->info);
// 			if (philo->info->times_eat == philo->eat_cycle)
// 				philo->eaten++;
// 			ft_usleep(philo->eat_time);
// 		}
// 	}
// }

void	think_to_eat(t_info *info)
{
	if (!(info->ptr->dead) && (info->state == thinking))
	{
		info->state = forking;
		sem_wait(info->ptr->sem);
		print_log(info);
		sem_wait(info->ptr->sem);
		print_log(info);
		// odd_philo(info);
		// even_philo(info);
		// if ((info->right == 1) && (info->left == 1))
		{
			info->death_timer = s_to_m() + info->ptr->death_time;
			info->state = eating;
			info->times_eat++;
			print_log(info);
			if (info->times_eat == info->ptr->eat_cycle)
				info->ptr->eaten++;
			ft_usleep(info->ptr->eat_time);
		}
	}
}