#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
	int filedes[2];
	char buf[BUF_SIZE];
	if(pipe(filedes)  == -1)
		exit(-1);

	int num_read = 0;
	switch(fork())
	{
		case -1:
			exit(-1);
		case 0:
			if(close(filedes[1]) == -1)
				exit(-1);
			for(;;)
			{
				num_read = read(filedes[0], buf, BUF_SIZE);
				if(num_read == -1)
					exit(-1);
				if(num_read == 0)
					break;
				if(write(STDOUT_FILENO, buf, num_read))
					exit(-1);
			}
			write(STDOUT_FILENO, "\n", 1);
			if(close(filedes[0]) == -1)
				exit(-1);
			exit(0);
		default:
			if(close(filedes[0]) == -1)
				exit(-1);
			if(write(filedes[1], argv[1], strlen(argv[1])) != strlen(argv[1])) 
				exit(-1);
			if(close(filedes[1]) == -1)
				exit(-1);
			wait(NULL);
		exit(0);
	}
}

