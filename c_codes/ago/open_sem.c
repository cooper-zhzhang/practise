#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

int main(int argc, char **argv)
{
	sem_t *sem;
	
	sem = sem_open(argv[1], 0);
	if(sem == SEM_FAILED)
		printf("error\n");
	else
		printf("success\n");
	return 0;
}
