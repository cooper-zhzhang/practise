#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	sigset_t mask;
	int sfd, j;
	int fd = -1;
	struct signalfd_siginfo fdsi;
	ssize_t s;
	printf("%s: PID = %ld\n", argv[0], (long)getpid());
	sigemptyset(&mask);
	for(j = 1; j < argc; ++j)
		sigaddset(&mask, atoi(argv[j]));
	if(sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
		exit(-1);
	sfd = signalfd(fd, &mask, 0);
	if(sfd == -1)
	{
		printf("error\n");
		exit(-1);
	}
	for(;;)
	{
		s = read(sfd, &fdsi, sizeof(struct signalfd_siginfo));
		if(s != sizeof(struct signalfd_siginfo))
			exit(-1);
		printf("%s: got signal %d\n", argv[0], fdsi.ssi_signo);
		if(fdsi.ssi_code == SI_QUEUE)
		{
			printf("; ssi_pid = %d; ", fdsi.ssi_pid);
			printf("ssi_int = %d", fdsi.ssi_int);
		}
		printf("\n");
	}
}

	
