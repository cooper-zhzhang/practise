#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
	int pfd[2];
	int j, dummy;
	if(argc < 2)
	{
		printf("aleep-time\n");
		exit(-1);
	}
	
	setbuf(stdout, NULL);

	if(pipe(pfd) == -1)
		exit(-1);
	
	for(j = 1; j < argc; ++j)
	{
		switch(fork())
		{
			case -1:
				exit(-1);
			case 0:
				if(close(pfd[0]) == -1)
					exit(-1);
			sleep(atoi(argv[j]));
			printf("child %d (PId=%ld) closeing pipe\n", 
			j, (long)getpid());
			if(close(pfd[1]) == -1)
				exit(-1);
			_exit(0);
		default:
			break;
		}
	}

	if(close(pfd[1]) == -1)
		exit(-1);
	
	if(read(pfd[0], &dummy, 1) != 0)
		exit(-1);
	printf("Parent ready to go\n");
	exit(0);
}
