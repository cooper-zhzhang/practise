#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("Initial value of USER: %s\n", getenv("USER"));
	if(putenv("USER=britta") != 0)
		exit(-1);
	execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char*)NULL);
	exit(0);
}
