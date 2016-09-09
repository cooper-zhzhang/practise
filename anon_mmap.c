#ifdef USE_MAP_ANON
#define _BSD_SOURCE
#endif
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int *addr;
#ifdef USE_MAP_ANON
	addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1 , 0);
	if(addr == MAP_FAILED)
		exit(-1);
#else
		int fd;
		fd = open("/dev/zero", O_RDWR);
		if(fd == -1)
			exit(-1);
		addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, fd, 0);
		if(addr == MAP_FAILED)
		exit(-1);
	
		if(close(fd) == -1)
			exit(-1);
#endif
		*addr = 1;
		
		switch(fork())
		{
			case -1:
				exit(-1);
			case 0:
				printf("child started, value = %d\n", *addr);
				(*addr) ++;

				if(munmap(addr, sizeof(int)) == -1)
					exit(-1);
				exit(0);
			default:
				if(wait(NULL) == -1)
					exit(-1);
				printf("in parent, value = %d\n", *addr);
				if(munmap(addr, sizeof(int)) == -1)
					exit(-1);
				exit(0);
		}
}
				



