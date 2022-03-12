#include "philosopher_bonus.h"


void	*handler(void *arg)
{
	// each process is threaded
	t_info *info;
	int		i;
	info = (t_info *)arg;

	//printf("hi\n");
	i = 0;
	while (i < 5)
	{
		if (info->state == thinking)
		{
			print_log(info);
			think_to_eat(info);
			eat_to_sleep(info);
			// sem_wait(philo->sem); // DECREMENT THE FORKS
			// sem_wait(philo->sem); 
			// sleep(1);
		//printf("pid: %d\n", getpid());	
			//printf("bye\n");
		}
		i++;
	}
	//printf("hi");
	return (NULL);
}

int	main(int argc, char **argv)
{	
	t_philo		*philo;
	char		*test;
	//pthread_t	t1;
	int			i;

	philo = init_threads(argc, argv);
	philo = init_states(philo);
	//philo = thread_create(philo);
	//printf("philo->num %d\n\n", philo->num);
	test = "test";
	sem_unlink(test);
	philo->sem = sem_open("test", O_CREAT, 0644 , 0); // CHECK PROPERLY THE INITIAL NUMBER
	
	i = -1;
	while (++i < philo->num) // populate forks (Get_dem_forks depening on philo)
	{
		sem_post(philo->sem);
		printf("post: %d\n", i);
	}
	printf("\n");
	i = -1;
	while (++i < philo->num)
	{
		if (fork() == 0)
		{
			//printf("thread create: %d\n", i);
			//printf("pid: %d\n", getpid());
			//pthread_create(&t1, NULL, handler, philo->info); 
			pthread_create(&philo->thread[i], NULL, &handler, &philo->info[i]); // sem_t in philo_t
			pthread_join(philo->thread[i], NULL);
			return (0);
		}
	}

	// i = -1;
	// while (++i < philo->num)
	// 	sem_wait(sem);
	sleep(1); // might need to work on this
	printf("exit\n");
	sem_close(philo->sem);
	sem_unlink(test);
	return (0);
}
