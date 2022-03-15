/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:29:29 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:29:29 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	print_log(t_info *info)
{
	pthread_mutex_lock(&info->ptr->miniphone);
	sem_wait(info->ptr->print);
	if (!info->ptr->dead)
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
	sem_post(info->ptr->print);
	pthread_mutex_unlock(&info->ptr->miniphone);
}
