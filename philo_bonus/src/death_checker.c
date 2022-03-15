/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:20:54 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:21:11 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*death_checker(void *arg)
{
	t_info		*info;

	info = arg;
	while (!(info->ptr->dead))
	{
		if (s_to_m() > info->death_timer)
		{
			sem_wait(info->ptr->print);
			info->ptr->dead = 1;
			sem_post(info->ptr->death);
			printf("%s%ld %d died%s\n", RED, s_to_m(), info->id, NC);
		}
		ft_usleep(1);
	}
	return (NULL);
}
