#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SYSNC_SIG SIGUSR1

static void handler(int sig)
{
}

int main(int argc, char **argv)
{
	pid_t childpid;
	sigset_t blockmask, origmask, emptymask;
	struct sigaction sa;

	setbuf(stdout, NULL);

	sigemptyset(&blockmask);
	sigaddset(&blockmask, SYSNC_SIG);
	if(sigprocmask(SIG_BLOCK, &blockmask, &origmask) == -1)
		exit(-1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;
	if(sigaction(SYSNC_SIG, &sa, NULL) == -1)
		exit(-1);
	
	switch(childpid = fork())
	{
		case -1:
			exit(-1);
		case 0:
			printf("%ld child started - doing some work\n",
						(long)getpid());
			sleep(2);
			printf("%ld child about to signal parent\n", (long)getpid());
			if(kill(getppid(), SYSNC_SIG) == -1)
				_exit(-1);
			_exit(EXIT_SUCCESS);
		default:
			printf("%ld parent about to wait for signal\n", (long)getpid());
			sigemptyset(&emptymask);
			if(sigsuspend(&emptymask) == -1 && errno != EINTR)
				exit(-1);
			printf("%ld parent got a signal\n", (long)getpid());
			if(sigprocmask(SIG_SETMASK, &origmask, NULL) == -1)
				exit(-1);
			exit(EXIT_SUCCESS);
	}
}
