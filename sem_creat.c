#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int flags, opt;
	mode_t perms = 666;

	unsigned int value = 0;
	sem_t *sem;

	flags = 0;
	while((opt = getopt(argc, argv, "cx")) != -1)
	{
		switch(opt)
		{
			case 'c': flags |= O_CREAT;
			case 'x': flags |= O_EXCL;
			default: exit(-1);
		}
	}
	if(optind > argc)
		exit(-1);
	sem = sem_open(argv[optind], flags, perms, value);
	if(sem == SEM_FAILED)
		exit(-1);
	sem_close(sem);
	sem_unlink(argv[optind]);
	exit(0);
}
