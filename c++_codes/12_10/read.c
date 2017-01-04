#include <stdio.h>
#include <fcntl.h>


int main()
{
	int fd;
	fd = open("a.out", O_RDONLY);
	unsigned char ch[100];
	int flag = read(fd, ch, 100);
	if(flag == -1)
	{
		printf("error\n");
		exit(-1);
	}

	for(int i = 0; i < flag; ++i)
	{
		if(i % 10 == 0)
			printf("\n");
		printf("%2x", ch[i]);
	}


	return 0;
}

