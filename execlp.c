#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	execlp(argv[1], argv[1], "hello, world", (char*)NULL);
	
	return -1;
}
