#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static int glo = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void* threadfunc(void *arg)
{
	int loop = *((int*)arg);
	int loc;
	for(int i = 0; i < loop; ++i)
	{
		int s;
		s = pthread_mutex_lock(&mtx);
		if(s != 0) exit(-1);
		loc = glo;
		++loc;
		glo = loc;
		s = pthread_mutex_unlock(&mtx);
		if(s != 0) exit(-1);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t t1, t2;
	int loops;
	loops = (argc > 1) ? atoi(argv[1]) : 1000000;
	int s;
	s = pthread_create(&t1, NULL, threadfunc, &loops);
	if(s == -1) exit(-1);

	s = pthread_create(&t2, NULL, threadfunc, &loops);
	if(s == -1) exit(-1);

	s = pthread_join(t1, NULL);
	if(s == -1) exit(-1);
	s = pthread_join(t2, NULL);
	if(s == -1) exit(-1);

	printf("%d\n", glo);
	pthread_mutex_destroy(&mtx);

	return 0;
}

