#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int flags, opt;
	mode_t perms;
	unsigned int value;
	sem_t *sem;
	sem_unlink("/de");
	sem_unlink("/dem");

	flags = 0;
	while((opt = getopt(argc, argv, "cx")) != -1)
	{
		switch(opt)
		{
			case 'x': flags |= O_CREAT; break;
			case 'c': flags |= O_EXCL; break;
			default: exit(-1);
		}
	}

	if(optind >= argc)
	{
		printf("argam error\n");
		exit(-1);
	}

	
	perms = (argc <= optind + 1) ? (S_IRUSR | S_IWUSR) : atoi(argv[optind]);
	value = (argc <= optind + 2) ? 0 : atoi(argv[optind+2]);

	printf("%ld\n", (long)flags);
	sem = sem_open(argv[optind], flags, perms, value);
	if(sem == SEM_FAILED)
	{
		printf("sem_open error\n");
		exit(-1);
	}
	
	printf("success\n");
	return 0;
}
