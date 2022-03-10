#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  

  
void* thread(void* arg)
{
	sem_t *mutex;
	mutex = (sem_t *)arg;
    //wait
    sem_wait(mutex);
    printf("\nEntered..\n");
  
    //critical section
    sleep(1);
      
    //signal
    printf("\nJust Exiting...\n");
    sem_post(mutex);
	return (NULL);
}
  
  
int main(void)
{
	sem_t	*mutex;
	char	*test;

	test = "./test";
	sem_unlink(test);
	mutex = sem_open(test, O_CREAT, 0644, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,mutex);
    sleep(2);
    pthread_create(&t2,NULL,thread,mutex);
	//printf("hi\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
	sem_close(mutex);
    sem_unlink(test);
    return 0;
}
