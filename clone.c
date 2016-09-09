#define _GNU_SOURCE
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#ifndef CHILD_SIG
#define CHILD_SIG SIGUSR1

#endif

static int childfunc(void *arg)
{
	if(close(*((int*)arg)) == -1)
		exit(-1);
	return 0;
}

int main(int argc, char **argv)
{
	const int STACK_SIZE = 65536;
	char *stack;
	char *stacktop;
	int s, fd, flags;

	fd = open("/dev/null", O_RDWR);
	if(fd == -1)
		exit(-1);
	
	flags = (argc > 1) ? CLONE_FILES : 0;

	stack = malloc(STACK_SIZE);
	if(stack == NULL)
		exit(-1);
	stacktop = stack + STACK_SIZE;

	if(CHILD_SIG != 0 && CHILD_SIG != SIGCHLD)
		if(signal(CHILD_SIG, SIG_IGN) == SIG_ERR)
			exit(-1);
	if(clone(childfunc, stacktop, flags | CHILD_SIG, (void*)&fd) ==-1)
		exit(-1);
	if(waitpid(-1, NULL, (CHILD_SIG != SIGCHLD) ? __WCLONE : 0) == -1)
		exit(-1);
	printf("child has terminated\n");

	s = write(fd, "x", 1);
	if(s == -1 && errno == EBADF)
		printf("file descriptor %d has been closed\n", fd);
	else if(s == -1)
		printf("write() on file descriptor %d failed "
						"unexpectedly (%s)\n", fd, strerror(errno));
	else
		printf("write() on file descriptor %d duccess\n", fd);
	return 0;
}

