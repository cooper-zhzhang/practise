#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int isstack = 222;

	switch(vfork())
	{
		case -1:
			exit(-1);
		case 0:
			sleep(3);
			write(STDOUT_FILENO, "child executing\n", 16);
			isstack *= 3;
			_exit(EXIT_SUCCESS);
		default:
			write(STDOUT_FILENO, "parent executing\n", 17);
			printf("isstack=%d\n", isstack);
			exit(EXIT_SUCCESS);
	}
}

