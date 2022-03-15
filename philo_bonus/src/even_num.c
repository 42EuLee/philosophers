/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:28:51 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 11:28:52 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	even_num(int num)
{
	if (num == 0)
		return (1);
	if (num % 2 == 0)
		return (1);
	return (0);
}
