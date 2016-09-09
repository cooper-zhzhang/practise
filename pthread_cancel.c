#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static void* thread_func(void* arg)
{
	int j;
	int i = -1;
	printf("New thread started\n");
	for(j = 1; ;++j)
	{
		printf("Loop %d\n", j);
		sleep(1);
//		i++;
	//	pthread_testcancel();
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thr;
	int s;
	void *res;

	s = pthread_create(&thr, NULL, thread_func, NULL);
	if(s != 0)
		exit(-1);
	
	sleep(3);

	s = pthread_cancel(thr);
	if(s != 0)
		exit(-1);
	s =pthread_join(thr, &res);
	if(s != 0)
		exit(-1);
	
	if(res == PTHREAD_CANCELED)
		printf("thread was canceled \n");
	else
		printf("thread was not canceled (should not happen!)\n");
	exit(0);
}
