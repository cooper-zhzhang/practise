#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int system(char *command)
{
	int status;
	pid_t childpid;

	switch(childpid = fork())
	{
		case -1:
			return -1;
		case 0:
			execl("/bin/sh", "sh", "-c", command, (char*)NULL);
			_exit(127);
		default:
			if(waitpid(childpid, &status, 0) == -1)
				return -1;
			else
				return status;
		}
}

