#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int flag;
	int domain = AF_INET;
	char src_str1[] =  "202.201.114.75";
	char src_str2[] =  "::1";
	struct in_addr addr;
	flag = inet_pton(domain, src_str1, &addr);
	printf("%d\n", addr.s_addr);

	struct in6_addr addr6;
	flag = inet_pton(AF_INET6, src_str2, &addr);
	printf("%s\n", addr6.s6_addr);
	return 0;
}

