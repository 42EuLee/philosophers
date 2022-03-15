/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_to_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:23 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:27:28 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*even_philo(t_info *info)
{
	if (!(info->ptr->dead) && (even_num(info->id) == 1))
	{
		if ((pthread_mutex_lock(&info->ptr->fork[info->id]) == 0))
		{
			info->right = 1;
			print_log(info);
		}
		if (info->ptr->num == 1)
			return (NULL);
		if ((pthread_mutex_lock(&info->ptr->fork[(info->id + 1)
						% info->ptr->num]) == 0) && (info->right == 1))
		{
			info->left = 1;
			print_log(info);
		}
	}
	return (NULL);
}

void	*odd_philo(t_info *info)
{
	if (!(info->ptr->dead) && (odd_num(info->id) == 1))
	{
		if (pthread_mutex_lock(&info->ptr->fork[(info->id + 1)
					% info->ptr->num]) == 0)
		{
			info->left = 1;
			print_log(info);
		}
		if (info->ptr->num == 1)
			return (NULL);
		if ((pthread_mutex_lock(&info->ptr->fork[info->id]) == 0)
			&& (info->left == 1))
		{
			info->right = 1;
			print_log(info);
		}
	}
	return (NULL);
}

void	think_to_eat(t_info *info)
{
	if (!(info->ptr->dead) && (info->state == thinking))
	{
		info->state = forking;
		odd_philo(info);
		even_philo(info);
		if ((info->right == 1) && (info->left == 1))
		{
			info->death_timer = s_to_m() + info->ptr->death_time;
			info->state = eating;
			info->times_eat++;
			print_log(info);
			if (info->times_eat == info->ptr->eat_cycle)
				info->ptr->eaten++;
			ft_usleep(info->ptr->eat_time);
		}
	}
}
