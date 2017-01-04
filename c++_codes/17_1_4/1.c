#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define LENGTH 256
int main(int argc, char**argv)
{
	int readFd;
	int writeFd;
	assert(argc == 3);
	
	if((readFd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("open 1 error\n");
		exit(-1);
	}
	if((writeFd = open(argv[2], O_CREAT|O_RDWR, 0666)) == -1)
	{
		printf("open 2 error\n");
		exit(-1);
	}
	unsigned char file[LENGTH];

	int count = 0;
	while(1){
		memset(file, LENGTH, 0);
		count = read(readFd, file, LENGTH);
		if(count == -1)
		{
			exit(-1);
		}
		else if(count == 0)
		{
			break;
		}
		write(writeFd, file, count);
	}

	return 0;
}
