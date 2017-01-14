#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void* threadfunc(void *arg)
{
	char *s = (char*)arg;
	printf("%s", s);
	printf("%s", s);
	return (void*) strlen(s);
}

int main(int argc, char **argv)
{
	pthread_t t1;
	void *res;
	int s;

	s = pthread_create(&t1, NULL, threadfunc, "hello, world\n");
	if(s != 0)
		exit(-1);
	printf("Message from main()\n");
	s = pthread_join(t1, &res);
	if(s != 0)
		exit(-1);
	printf("Thread returned %ld\n", (long)res);
	return 0;
}
