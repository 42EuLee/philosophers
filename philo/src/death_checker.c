/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:25:51 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:26:08 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	death_checker(t_philo *philo)
{
	int	i;

	while (!philo->dead)
	{
		i = 0;
		if (philo->eaten == philo->num)
			return ;
		while (!(philo->dead) && (i < philo->num))
		{
			if (s_to_m() > philo->info[i].death_timer)
			{
				philo->dead = 1;
				print_log(&philo->info[i]);
				break ;
			}
			i++;
			ft_usleep(10);
		}
	}
}
