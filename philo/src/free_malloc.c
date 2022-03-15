/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:25:57 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:26:06 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_malloc(t_philo *philo)
{
	free(philo->info);
	free(philo->fork);
	free(philo->thread);
	free(philo);
}
