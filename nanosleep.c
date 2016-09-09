#define _POSIX_C_SOURCE 199309
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>

static void siginthandler(int sig)
{
	return;
}

int main(int argc, char **argv)
{
	struct timeval start, finish;
	struct timespec request, remain;
	struct sigaction sa;
	int s;
	request.tv_sec = atol(argv[1]);
	request.tv_nsec = atol(argv[2]);

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = siginthandler;
	if(sigaction(SIGINT, &sa, NULL) == -1)
		exit(-1);
	if(gettimeofday(&start, NULL) == -1)
		exit(-1);
	for(;;)
	{
		s = nanosleep(&request, &remain);
		if(s == -1 && errno != EINTR)
			exit(-1);
		if(gettimeofday(&finish, NULL) == -1)
			exit(-1);
		printf("Sleep for: %9.6f secs\n", finish.tv_sec - start.tv_sec + (finish.tv_usec - start.tv_usec) / 1000000.0);

		if(s == 0)
			break;
		printf("Remaining: %2ld.%09ld\n", (long)remain.tv_sec, remain.tv_nsec);
 		request = remain;
	}
	printf("Slepp complete\n");
	return 0;
}
