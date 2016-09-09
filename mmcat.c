#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char *addr;
	int fd;
	struct stat sb;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		exit(-1);
	if(fstat(fd, &sb) == -1)
		exit(-1);
	addr = mmap(NULL,sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if(addr == MAP_FAILED)
		exit(-1);
	if(write(STDOUT_FILENO, addr, sb.st_size) != sb.st_size)
		exit(-1);
	munmap(addr, sb.st_size);
	exit(0);
}
