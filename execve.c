#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *argvec[10];
	char *envvec[] = {"GREET=salut", "BYE=adieu", NULL};

	argvec[0] = strrchr(argv[1], '/');
	if(argvec[0] != NULL)
		argvec[0]++;
	else
		argvec[0] = argv[1];
	argvec[1] = "hello world";
	argvec[2] = "goodbye";
	argvec[3] = "hell world";
	argvec[4] = NULL;

	execve(argv[1], argvec, envvec);
	exit(0);
}


