#define _POSIX_C_SOURCE 199309
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int sig, numsigs, sigdata;
	union sigval sv;
	printf("%s: PID is %ld, UID is %ld\n", argv[0], 
				(long) getpid(), (long)getuid());
	sig = atoi(argv[2]);
	sigdata = atoi(argv[3]);
	numsigs = (argc > 4) ? atoi(argv[4]) : 1;
	for(int j = 0; j < numsigs; ++j)
	{
		sv.sival_int = sigdata + j;
		if(sigqueue(atol(argv[1]), sig, sv) == -1)
			exit(-1);
	}
	return 0;
}

