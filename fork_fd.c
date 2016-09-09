#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
	int fd;
	if((fd = open(argv[1], O_WRONLY)) == -1)
		exit(-1);
	else
		printf("open success\n");

	char buff[BUF_SIZE] = "dsdsdsdsdsdsdsa";

	pid_t childpid;
	switch(childpid = fork())
	{
		case -1:
			exit(-1);
		case 0:
			if(write(fd, buff, BUF_SIZE) == -1)
				printf("child fail\n");
			close(fd);
			_exit(0);
		default:
			sleep(5);
			if(write(fd, buff, BUF_SIZE) == -1)
				printf("fail\n");
	}

	return 0;
}
