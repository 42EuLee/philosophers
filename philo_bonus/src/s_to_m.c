/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:29:31 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:29:31 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

long	s_to_m(void)
{
	struct timeval	current_time;
	long long		ms;

	gettimeofday(&current_time, NULL);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ms);
}
