#include "philosopher.h"

typedef struct s_philob
{
	int		num;
	int		death_time;
	int		eat_time;
	int		sleep_time;
	int		eat_cycle;
}	t_philob;

void	*handler(void *arg)
{
	sem_t	*sem;
	static int		i;
	sem = (sem_t *)arg;

	i = 0;
	//while (i < 10)
	{
		//printf("hi\n");
		sem_wait(sem);
		sleep(1);
		printf("pid: %d\n", getpid());	

		//printf("bye\n");
		sem_post(sem);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{	
	sem_t	*sema;
	t_philob *philo;
	char	*test;
	pthread_t	t1;
	int			i;
	philo = (t_philob *)malloc(sizeof(t_philob));

	philo->num = 2;
	printf("philo->num %d\n\n", philo->num);
	test = "./test";
	sem_unlink(test);
	sema = sem_open("/test", O_CREAT, 0644 , 1); // CHECK PROPERLY THE INITIAL NUMBER
	// pthread_create(&t1, NULL, handler, sema);
	// //pthread_create(&t2, NULL, handler, sema);
	// pthread_join(t1, NULL);
	// //pthread_join(t2, NULL);
	
	i = 0;
	//fork();
	// while (i < philo->num)
	// {
	// 	if (printf("Fork return: %d\n", fork() == 0))
	// 	{
			
	// 		pthread_create(&t1, NULL, handler, sema);
	// 		pthread_join(t1, NULL);
	// 		printf("PID: %d\n", getpid());
	// 		exit(0);
	// 	}
	// 	i++;
	// }
	
	while (i < 3)
	{
		if (fork() == 0)
		{
			pthread_create(&t1, NULL, handler, sema);
			pthread_join(t1, NULL);
			
			return (0);
		}
		i++;
	}

	// i = -1;
	// while (++i < 3)
	// 	sem_wait(sema);
	printf("exit\n");

	sem_close(sema);
	sem_unlink(test);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	fork();
// 	printf("hi\n");
// }
