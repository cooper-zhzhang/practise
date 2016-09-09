#define _GNU_SOURCE
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int handlersleeptime;
static volatile int sigcnt = 0;
static volatile int alldone = 0;

static void handler(int sig, siginfo_t *si, void* ucontext)
{
	if(sig == SIGINT || sig == SIGTERM)
	{
		alldone = 1;
		return;
	}

	sigcnt ++;
	printf("caught signal %d\n",sig);
	printf("si_signo=%d, si_code=%d(%s), ", si->si_signo, si->si_code,
				(si->si_code == SI_USER) ? "SI_USER" :
				(si->si_code == SI_QUEUE) ? "SI_QUEUE" : "other");
	printf("si_value=%d\n", si->si_value.sival_int);
	printf(" si_pid=%ld, si_uid=%ld\n", (long)si->si_pid, (long)si->si_uid);
	sleep(handlersleeptime);

}

int main(int argc, char ** argv)
{
	struct sigaction sa;
	int sig;
	sigset_t prevmask, blockmask;
	
	printf("%s: PID is %ld\n", argv[0], (long)getpid());
	handlersleeptime = (argc > 2) ? atoi(argv[2]) : 1;
	
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigfillset(&sa.sa_mask);

	for(sig = 1; sig < NSIG; ++sig)
		if(sig != SIGTSTP && sig != SIGQUIT)
			sigaction(sig, &sa, NULL);
	while(!alldone)
		pause();

	return 0;
}
