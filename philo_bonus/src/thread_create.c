/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:31:07 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:31:08 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_philo	*thread_create(t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	while (i < philo->num)
	{
		error = pthread_create(&philo->thread[i], NULL, &routine,
				&philo->info[i]);
		if (error != 0)
			printf("\n Thread can't be created: [%s]", strerror(error));
		i++;
	}
	return (philo);
}
