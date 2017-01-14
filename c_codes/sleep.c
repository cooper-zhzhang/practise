#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void handle(int sig)
{
	if(sig == 2)
		printf("caugt a sig 2\n");
}

int main(int argc, char **argv)
{
	printf("PID=: %d\n", getpid());
	int seconds = atoi(argv[1]);
	signal(2, handle);
	unsigned int remain = sleep(seconds);
	if(remain != 0)
	{
		printf("sleep was break: %d\n", fremain);
	}
	return 0;
}


