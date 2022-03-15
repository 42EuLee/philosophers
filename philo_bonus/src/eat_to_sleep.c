/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_to_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:23:21 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:24:49 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	eat_to_sleep(t_info *info)
{
	if (info->state == eating)
	{
		sem_post(info->ptr->sem);
		sem_post(info->ptr->sem);
		if (info->times_eat == info->ptr->eat_cycle)
		{
			sem_post(info->ptr->eaten);
			exit(0);
		}
		info->state = sleeping;
		print_log(info);
		ft_usleep(info->ptr->sleep_time);
		info->state = thinking;
		usleep(50);
	}
}
