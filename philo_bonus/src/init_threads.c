/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:23:10 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:23:13 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_philo	*malloc_objects(t_philo *philo)
{
	philo->info = (t_info *)malloc(sizeof(t_info) * philo->num);
	philo->thread = malloc(sizeof(pthread_t) * philo->num);
	philo->pid = malloc(sizeof(pid_t) * philo->num);
	philo->eat_thread = malloc(sizeof(pthread_t));
	philo->death_thread = malloc(sizeof(pthread_t));
	return (philo);
}

t_philo	*init_threads(int argc, char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->num = ft_atoi(argv[1]);
	philo->death_time = (ft_atoi(argv[2]));
	philo->eat_time = ft_atoi(argv[3]) * 1000;
	philo->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
	{
		philo->eat_cycle = ft_atoi(argv[5]);
		philo->eaten = 0;
	}
	else
		philo->eat_cycle = -1;
	pthread_mutex_init(&philo->miniphone, NULL);
	philo = malloc_objects(philo);
	return (philo);
}
