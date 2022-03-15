/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_to_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:25:53 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:26:07 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat_to_sleep(t_info *info)
{
	if (info->state == eating)
	{
		pthread_mutex_unlock(&info->ptr->fork[info->id]);
		pthread_mutex_unlock(&info->ptr->fork[(info->id + 1) % info->ptr->num]);
		if (!info->ptr->dead)
			info->state = sleeping;
		print_log(info);
		ft_usleep(info->ptr->sleep_time);
		info->left = 0;
		info->right = 0;
		if (!info->ptr->dead)
			info->state = thinking;
		print_log(info);
	}
}
