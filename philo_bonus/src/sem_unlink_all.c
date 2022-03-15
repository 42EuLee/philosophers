/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_unlink_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:30:54 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:30:55 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	sem_unlink_all(t_philo *philo)
{
	sem_unlink(philo->semstr);
	sem_unlink(philo->deathstr);
	sem_unlink(philo->eatenstr);
	sem_unlink(philo->printstr);
}
