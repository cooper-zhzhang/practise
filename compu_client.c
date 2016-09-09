#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>

#define MES_MAX 1000

int main(int argc, char **argv)
{

	fflush(stdout);
	int clfd;
	int  mes[MES_MAX];
	for(int i = 0; i < MES_MAX; ++i)
		mes[i] = (i + 1);


	clfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in seraddr;

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[1]));
	inet_pton(AF_INET, "127.0.0.1", &(seraddr.sin_addr));
	connect(clfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
	//int num = write(clfd, mes, sizeof(mes));
	int num = write(clfd, mes, sizeof(int) * atoi(argv[2]));
	printf("client pass %d, success %lu\n", atoi(argv[2]), num/sizeof(int)); 
	for(int i = 0; i < MES_MAX; ++i)
		printf("%d ", mes[i]);
	printf("\n");

	fflush(stdout);
	int count = 0;
	num = read(clfd, &count, sizeof(int));
	printf("success read %lu \n%d\n", num/sizeof(int), count);
	return 0;
}
