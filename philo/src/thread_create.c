/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:25 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:27:27 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*thread_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num)
		pthread_create(&philo->thread[i], NULL, &routine, &philo->info[i]);
	return (philo);
}
