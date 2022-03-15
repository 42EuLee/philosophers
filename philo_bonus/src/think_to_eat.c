/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_to_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:22:18 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:31:05 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	think_to_eat(t_info *info)
{
	if (!(info->ptr->dead) && (info->state == thinking))
	{
		info->state = forking;
		sem_wait(info->ptr->sem);
		print_log(info);
		sem_wait(info->ptr->sem);
		print_log(info);
		info->death_timer = s_to_m() + info->ptr->death_time;
		info->state = eating;
		info->times_eat++;
		print_log(info);
		ft_usleep(info->ptr->eat_time);
	}
}
