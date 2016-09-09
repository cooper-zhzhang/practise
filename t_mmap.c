#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#define MEM_SIZE 10

int main(int argc, char **argv)
{
	char *addr;
	int fd;
	fd = open(argv[1], O_RDWR);
	if(fd == -1)
		exit(-1);
	
	addr = mmap(NULL, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED)
		exit(-1);
	
	if(close(fd) == -1)
		exit(-1);
	
	printf("current string %.*s\n", MEM_SIZE, addr);

	if(argc > 2)
	{
		if(strlen(argv[2]) > MEM_SIZE)
			exit(-1);
		//memset(addr, 0, MEM_SIZE);
		strncpy(addr, argv[2], strlen(argv[2]));
		if(msync(addr, MEM_SIZE, MS_SYNC) == -1)
			exit(-1);

		printf("copied \"%s\" to shared memory\n", argv[2]);
	}
	
exit(0);
}
