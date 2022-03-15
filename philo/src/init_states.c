/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:22:20 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:22:21 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*init_states(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		philo->info[i].id = i;
		philo->info[i].state = thinking;
		philo->info[i].ptr = philo;
		philo->info[i].times_eat = 0;
		philo->info[i].death_timer = s_to_m() + philo->death_time;
		i++;
	}
	philo->dead = 0;
	return (philo);
}
