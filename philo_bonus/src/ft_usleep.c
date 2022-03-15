/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:29:13 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:29:15 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	ft_usleep(int sleep)
{
	long long	begin;
	long long	current;

	begin = s_to_m();
	while (1)
	{
		current = s_to_m();
		if (((current - begin) * 1000) >= (long)sleep)
			break ;
		usleep(100);
	}
}
