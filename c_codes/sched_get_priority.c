#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int which = SCHED_RR;
	printf("%d\n", sched_get_priority_min(which));
	printf("%d\n", sched_get_priority_max(which));
	return 0;
}
