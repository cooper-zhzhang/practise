#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	fd = open(argv[1], O_RDWR);
	int flag;
	flag = fcntl(fd, F_GETFL);
	int fd_copy;

	fd_copy = fcntl(fd, F_DUPFD, 4);
	printf("%d %d\n", fd, fd_copy);

	printf("%d\n", flag);

	return 0;
}
