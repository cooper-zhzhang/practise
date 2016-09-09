#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int flags;
	if(argc > 1)
	{
		flags = fcntl(STDOUT_FILENO, F_GETFD);
		if(flags == -1)
			exit(-1);
		flags |= FD_CLOEXEC;

		if(fcntl(STDOUT_FILENO, F_SETFD, flags) == -1)
			exit(-1);
	}
	execlp("ls", "ls", "-l", argv[0], (char*)NULL);
	exit(0);
}

