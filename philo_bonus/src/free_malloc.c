/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:28:54 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:29:08 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	free_malloc(t_philo *philo)
{
	free(philo->info);
	free(philo->thread);
	free(philo->pid);
	free(philo->eat_thread);
	free(philo->death_thread);
	free(philo);
}
