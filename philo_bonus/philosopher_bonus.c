#include "philosopher_bonus.h"


void	*handler(void *arg)
{
	t_info *info;
	info = (t_info *)arg;

	while (!info->ptr->dead && info->ptr->eaten < info->ptr->num)
	{
		if (info->state == thinking)
		{
			print_log(info);
			think_to_eat(info);
			eat_to_sleep(info);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{	
	t_philo		*philo;
	char		*test;
	char		*death;
	int			i;

	philo = init_threads(argc, argv);
	philo = init_states(philo);
	//printf("philo->num %d\n\n", philo->num);
	test = "test";
	death = "death";
	sem_unlink(test);
	sem_unlink(death);
	philo->sem = sem_open("test", O_CREAT, 0644 , 0); // CHECK PROPERLY THE INITIAL NUMBER
	philo->death = sem_open("death", O_CREAT, 0644 , 0);
	
	i = -1;
	while (++i < philo->num) // populate forks (Get_dem_forks depening on philo)
	{
		sem_post(philo->sem);
		//printf("post: %d\n", i);
	}
	i = -1;
	while (++i < philo->num)
	{
		if (fork() == 0)
		{
			//printf("thread create: %d\n", i);
			//printf("pid: %d\n", getpid());
			//pthread_create(&t1, NULL, handler, philo->info);

			//death_checker per process
			pthread_create(&philo->thread[i], NULL, &death_checker, &philo->info[i]); 
			handler(&philo->info[i]); 
			pthread_join(philo->thread[i], NULL);
			return (0);
		}
	}
	i = 0;
	while (i++ < philo->num)
	{
		sem_wait(philo->death);
		sem_post(philo->death);
	}
	sem_close(philo->sem);
	sem_unlink(test);
	sem_close(philo->death);
	sem_unlink(death);
	system("leaks philo_bonuss");
	return (0);
}
