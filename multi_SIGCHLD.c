#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static volatile int numlivechildren = 0;

static void sigchlhandler(int sig)
{
	int status, saveerrno;
	pid_t childpid;

	saveerrno = errno;

	printf("handler: caught SIGCHLD\n");

	while((childpid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		printf("handler: reaped child %ld-\n", (long) childpid);
		numlivechildren--;
	}

	if(childpid == -1 && errno != ECHILD)
		exit(-1);
	sleep(5);
	printf("handler: returning\n");
	errno = saveerrno;
}

int main(int argc, char **argv)
{
	int j, sigcnt;
	sigset_t blockmask, emptymask;
	struct sigaction sa;

	setbuf(stdout, NULL);
	sigcnt = 0;
	numlivechildren = argc - 1;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigchlhandler;
	if(sigaction(SIGCHLD, &sa, NULL) == -1)
		exit(-1);
	sigemptyset(&blockmask);
	sigaddset(&blockmask, SIGCHLD);
	if(sigprocmask(SIG_SETMASK, &blockmask, NULL) == -1)
		exit(-1);
	for(j = 1; j < argc; ++j)
	{
		switch(fork())
		{
			case -1:
				exit(-1);
			case 0:
				sleep(atoi(argv[j]));
				printf("child %d (PID=%ld) exiting\n", j, (long)getpid());
				_exit(0);
			default:
				break;
		}
	}

	sigemptyset(&emptymask);
	while(numlivechildren > 0)
	{
		if(sigsuspend(&emptymask) == -1 && errno != EINTR)
			exit(-1);
		sigcnt ++;
	}
	printf("all %d children have terminated;SIGCHLD was caught %d times\n", argc -1, sigcnt);
	exit(0);
}
