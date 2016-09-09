#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

static int glob = 0;
static sem_t sem;

static void* thread_func(void *arg)
{
	int loops = *(int*)arg;
	int loc, j;

	for(j = 0; j < loops; ++j)
	{
		if(sem_wait(&sem) == -1)
		{
			printf("sem_wait error\n");
			exit(-1);
		}

		loc = glob;
		++loc;
		glob = loc;

		if(sem_post(&sem) == -1)
		{
			printf("sem_post error\n");
			exit(-1);
		}
	}
	return NULL;
}

		
int main(int argc, char **argv)
{
	pthread_t t1, t2;
	int loops, s;

	loops = (argc > 1) ? atol(argv[1]) : 10000000;

	if(sem_init(&sem, 0, 1) == -1)
	{
		printf("sem_init error\n");
		exit(-1);
	}

	s = pthread_create(&t1, NULL, thread_func, &loops);
	if(s != 0)
	{
		printf("pthread_create error\n");
		exit(-1);
	}
	s = pthread_create(&t2, NULL, thread_func, &loops);
	if(s != 0)
	{
		printf("pthread_create error\n");
		exit(-1);
	}

	s = pthread_join(t1, NULL);
	if(s != 0)
	{
		printf("pthread_join error\n");
		exit(-1);
	}
	s = pthread_join(t2, NULL);
	if(s != 0)
	{
		printf("pthread_join error\n");
		exit(-1);
	}

	printf("glob = %d\n", glob);
	sem_destroy(&sem);
	return 0;
}

