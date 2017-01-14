#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char **argv)
{
	int pr = getpriority(PRIO_PROCESS, 0);
	printf("%d\n", pr);
	return 0;
}
