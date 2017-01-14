#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int prio, which;
	id_t who;
	which = (argv[1][0] == 'p') ? PRIO_PROCESS : ((argv[1][0] == 's') ? PRIO_USER : PRIO_PGRP);
	int s;
	who = atoi(argv[2]);
	prio = atoi(argv[3]);
	errno = 0;
	s = getpriority(which, who);
	if( s == -1 && errno != 0)
		exit(-1);
	printf("%ld PID`s %d\n",(long)who, s);
	
	s = setpriority(which, who, prio);
	if(s == -1)
		exit(-1);
	s = getpriority(which, who);
	if( s == -1 && errno != 0)
		exit(-1);
	printf("%ld PID`s %d\n",(long)who, prio);

	return 0;
}
