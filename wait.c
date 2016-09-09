#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int numdead;
	pid_t childpid;
	int j;
	setbuf(stdout, NULL);

	for(j = 1; j < argc; ++j)
	{
		switch(fork())
		{
			case -1:
				exit(-1);
			case 0:
				printf("child %d started with PID %ld, sleeping %s \n",
							j, (long)getpid(), argv[j]);
				sleep(atoi(argv[j]));
				_exit(0);
			default:
				break;
		}
	}
	
	numdead = 0;
	for(;;)
	{
		childpid = wait(NULL);
		if(childpid == -1)
		{
			if(errno == ECHILD)
			{
				printf("No more children - bye\n");
				exit(0);
			}
			else
			{
				exit(-1);
			}
		}
		numdead ++;
		printf("wait() returned child PID %ld (numdead=%d\n", (long)childpid, numdead);
	}
}

