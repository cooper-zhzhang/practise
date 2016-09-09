#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static volatile sig_atomic_t gotalarm = 0;

static void displaytimes(const char *msg, int includetimer)
{
	struct itimerval itv;
	static struct timeval start;
	struct timeval curr;
	static int callnum = 0;
	if(callnum == 0)
		if(gettimeofday(&start, NULL) == -1)
			exit(-1);
	if(callnum % 20 == 0)
		printf("elapsed value interval\n");
	if(gettimeofday(&curr, NULL) == -1)
		exit(-1);
	printf("%-7s %6.2f", msg.curr.tv_sec - start.tv_sec + (curr.tv_usec - start.tv_usec) / 1000000.0);
	if(includetimer)
	{
		if(getitimer(ITIMER_REAL, &itv) == -1)
			exit(-1);
		printf(" %6.2f %6.2f", itv.it_value.tv_sec, + itv.it_value.tv_usec / 1000000.0, itv.it_interval.tv_sec + itv.it_interval.tv_sec / 1000000.0);
	}
	printf("\n");
	++callnum;
}
static void sigalrmhandler(int sig)
{
	gotalarm = 1;
}

int main(int argc, char **argv)
{

