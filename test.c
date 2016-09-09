#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
//	int lim = sysconf(_SC_ATEXIT_MAX);
//	printf("%d\n", lim);
//	int a;
//	float b;
//	(void)( &a == &b);
	/*
	int n = ~0;
	int count = 0;
	unsigned int s = n;
	printf("%d\n", n);
	while(n != 0)
	{
		count++;
		n = n << 1;
	}
	printf("%d\n", count);
	count = 1;
	while(s= ((s>>1)&s))
	{
	count++;
	}
	printf("%d\n", count);
	*/
	/*
	for(int i = 0; i < 255; ++i)
	{
		printf("%c %d ", (char)i, i);
	}
	*/
	union
	{
		int i;
		char x[2];
	}a;
	memset(&a, 0, sizeof(a));
	a.x[0] = 10;
	a.x[1] = 1;
	printf("%d\n", a.i);

	return 0;
}
