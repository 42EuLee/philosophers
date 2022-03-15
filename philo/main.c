/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:26:14 by leu-lee           #+#    #+#             */
/*   Updated: 2022/03/15 16:41:56 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{	
	int		i;
	t_philo	*philo;

	if (check_invalid(argc, argv) == 1)
	{
		printf("Error\n");
		return (1);
	}
	philo = init_threads(argc, argv);
	philo = init_states(philo);
	philo = thread_create(philo);
	death_checker(philo);
	i = -1;
	while (++i < philo->num)
		pthread_join(philo->thread[i], NULL);
	i = -1;
	while (++i < philo->num)
		pthread_mutex_destroy(&philo->fork[i]);
	pthread_mutex_destroy(&philo->miniphone);
	free_malloc(philo);
	system("leaks philo");
	return (0);
}
