#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>

#define BUF_SIZE 10
#define PORT_NUM 5002

int main(int argc, char **argv)
{
	int sfd, j;
	struct sockaddr_in6 svaddr;
	size_t num_bytes;
	size_t msg_len;
	char resp[BUF_SIZE];

	sfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if(sfd == -1)
		exit(-1);
	
	memset(&svaddr, 0, sizeof(svaddr));
	svaddr.sin6_family = AF_INET6;
	svaddr.sin6_port = htons(PORT_NUM);
	if(inet_pton(AF_INET6, argv[1], &svaddr.sin6_addr) <= 0)
		exit(-1);
	
	for(j = 2; j < argc; ++j)
	{
		msg_len = strlen(argv[j]);
		if(sendto(sfd, argv[j], msg_len, 0, (struct sockaddr*)&svaddr, sizeof(svaddr)) != msg_len)
			exit(-1);
		num_bytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
		if(num_bytes == -1)
			exit(-1);
		printf("Response %d: %.*s\n", j - 1, (int)num_bytes, resp);
	}

	return 0;
}




