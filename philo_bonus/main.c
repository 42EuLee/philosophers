/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:25:06 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 16:40:48 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*eat_check(void *arg)
{
	static int	i;
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (i++ < philo->num)
		sem_wait(philo->eaten);
	sem_post(philo->death);
	return (NULL);
}

void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (!info->ptr->dead)
	{
		if (info->state == thinking)
		{
			print_log(info);
			think_to_eat(info);
			eat_to_sleep(info);
		}
	}
	return (NULL);
}

void	philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
		{
			pthread_create(&philo->thread[i], NULL, &death_checker,
				&philo->info[i]);
			routine(&philo->info[i]);
			pthread_join(philo->thread[i], NULL);
		}
	}
}

int	main(int argc, char **argv)
{	
	t_philo		*philo;
	int			i;

	if (check_invalid(argc, argv) == 1)
	{
		printf("Error\n");
		return (1);
	}
	philo = init_threads(argc, argv);
	philo = init_semaphores(philo);
	philo = init_states(philo);
	philo_create(philo);
	if (philo->eat_cycle > 0)
		pthread_create(philo->eat_thread, NULL, &eat_check, philo);
	sem_wait(philo->death);
	i = -1;
	while (++i < philo->num)
		kill(philo->pid[i], SIGTERM);
	sem_close_all(philo);
	sem_unlink_all(philo);
	free_malloc(philo);
	system("leaks philo_bonus");
	pthread_mutex_destroy(&philo->miniphone);
	return (0);
}
