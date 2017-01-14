#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 200

static void hangdler(int sig)
{
	printf("Caught signal\n");
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	char buf[BUF_SIZE];
	ssize_t numread;
	int saveerrno;

	sa.sa_flags = (argc > 2) ? SA_RESTART : 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = hangdler;
	if(sigaction(SIGALRM, &sa, NULL) == -1)
		exit(-1);
	alarm((argc > 1) ? atoi(argv[1]) : 10);
	numread = read(STDIN_FILENO, buf, BUF_SIZE - 1);
	saveerrno = errno;
	alarm(0);
	errno = saveerrno;

	if(numread == -1)
	{
		if(errno == EINTR)
			printf("Read timed out\n");
		else
			exit(-1);
		}
		else
		{
			printf("Successful read (%ld bytes): %.*s",
						(long)numread, (int)numread, buf);
		}
		
		return 0;
}
