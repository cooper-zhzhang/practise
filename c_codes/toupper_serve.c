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
#define IN6ADDR_INET {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}

void perr(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int main(int argc, char **argv)
{
	struct sockaddr_in6 svaddr, claddr;
	int sfd, j;
	size_t num_bytes;
	socklen_t len;
	char buf[BUF_SIZE];
	char claddrstr[64];

	sfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if(sfd == -1)
		perr("socket error");
	memset(&svaddr, 0, sizeof(struct sockaddr_in6));

	const struct in6_addr in6addr_any = IN6ADDR_INET; 
	svaddr.sin6_family = AF_INET6;
	svaddr.sin6_port = htons(PORT_NUM);
	svaddr.sin6_addr = in6addr_any;

	if(bind(sfd, (struct sockaddr*)&svaddr, sizeof(struct sockaddr_in6)) == -1)
		perr("bind error");
	
	for(;;)
	{
		len = sizeof(struct sockaddr_in6);
		num_bytes = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr*)&claddr, &len);
		
		if(num_bytes == -1)
			perr("recvfrom");
		
		if(inet_ntop(AF_INET6, &claddr.sin6_addr, claddrstr, 46) == NULL)
			printf("couldn`t convert client address to string\n");
		else
			printf("Server received %ld butys from (%s, %u)\n", (long)num_bytes, claddrstr, ntohs(claddr.sin6_port));

		for(j = 0; j < num_bytes; ++j)
			buf[j] = toupper((unsigned char) buf[j]);
		if(sendto(sfd, buf, num_bytes, 0, (struct sockaddr *)&claddr, len) != num_bytes)
			perr("sendto");
		}
}



