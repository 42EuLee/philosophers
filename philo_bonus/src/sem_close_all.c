/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_close_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:30:45 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:30:45 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	sem_close_all(t_philo *philo)
{
	static int	i;

	sem_close(philo->sem);
	sem_close(philo->death);
	while (i++ < philo->num)
		sem_post(philo->eaten);
	sem_close(philo->eaten);
	sem_close(philo->print);
}
