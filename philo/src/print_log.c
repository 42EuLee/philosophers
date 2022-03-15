/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:26:28 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:26:28 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_log(t_info *info)
{
	pthread_mutex_lock(&info->ptr->miniphone);
	if (!info->ptr->dead && info->ptr->eaten < info->ptr->num)
	{
		if (info->state == forking)
			printf("%s%ld %d has taken a fork\n%s", GREEN, s_to_m(),
				info->id, NC);
		if (info->state == thinking)
			printf("%s%ld %d is thinking\n%s", TEAL, s_to_m(), info->id, NC);
		if (info->state == sleeping)
			printf("%s%ld %d is sleeping\n%s", BLUE, s_to_m(), info->id, NC);
		if (info->state == eating)
			printf("%s%ld %d is eating\n%s", YELLOW, s_to_m(), info->id, NC);
	}
	if ((info->ptr->dead) == 1)
	{
		info->ptr->dead++;
		printf("%s%ld %d died%s\n", RED, s_to_m(), info->id, NC);
	}
	pthread_mutex_unlock(&info->ptr->miniphone);
}
