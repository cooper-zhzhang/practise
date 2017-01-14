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
	char mes[MES_MAX];
	for(int i = 0; i < MES_MAX; ++i)
		mes[i] = (i + 1);


	clfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in seraddr;

	seraddr.sin_family = AF_INET;
	//seraddr.sin_port = htons(atoi(argv[1]));
//	inet_pton(AF_INET, "127.0.0.1", &(seraddr.sin_addr));
	seraddr.sin_port = htons(atoi(argv[3]));
	inet_pton(AF_INET, argv[1], &(seraddr.sin_addr));
	connect(clfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
	//int num = write(clfd, mes, sizeof(mes));
	int num = write(clfd, mes, sizeof(char) * atoi(argv[2]));
	printf("client pass %d, success %lu\n", atoi(argv[2]), num/sizeof(int)); 
	for(int i = 0; i < MES_MAX; ++i)
		printf("%c ", mes[i]);
	printf("\n");

	fflush(stdout);
	num = read(clfd, &mes, sizeof(mes));
	printf("success read %d \n%*.s\n", num, num, mes);
	return 0;
}
