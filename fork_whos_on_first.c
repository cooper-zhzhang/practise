#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int numchildren, i;
	pid_t childpid;

	numchildren = atoi(argv[1]);

	setbuf(stdout, NULL);
	
	for(i = 0; i < numchildren; ++i)
	{
		switch(childpid = fork())
		{
			case -1:
				exit(-1);
			case 0:
				printf("%d child\n", i);
				_exit(EXIT_SUCCESS);
			default:
				printf("%d parent\n", i);
				wait(NULL);
				break;
		}
	}
	exit(EXIT_SUCCESS);
}
