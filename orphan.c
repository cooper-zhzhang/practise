#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>


int main(int argc, char **argv)
{
	pid_t childpid;

	switch(childpid = fork())
	{
		case -1:
			exit(-1);
		case 0:
			sleep(5);
			printf("gppid() = %ld\npthreadID %ld\n", (long)getppid(), (long)pthread_self());
			_exit(0);
		default:
			printf("parent %ld exit\npthreadID %ld", (long)getpid(),(long)pthread_self());
			exit(0);
	}
}

