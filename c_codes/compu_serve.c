#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>

#define MES_MAX 100

static void handle(int sig)
{
	int savederrno;
	savederrno = errno;
	while(waitpid(-1, NULL, WNOHANG) > 0);
	errno = savederrno;
}

int main(int argc, char **argv)
{
	int serfd;
	int clfd;
	int mes[MES_MAX];

	serfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in seraddr;
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle;
	if(sigaction(SIGCHLD, &sa, NULL) == -1)
		exit(-1);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[1]));
	if(inet_pton(AF_INET, "127.0.0.1", &(seraddr.sin_addr)) == 1);
	else
	{
		printf("error1\n");
		exit(-1);
	}
	if(-1 == bind(serfd, (struct sockaddr*)&seraddr, sizeof(struct sockaddr_in)))
	{
		printf("error bind\n");
		exit(-1);
	}
	if(listen(serfd, 5)  == -1)
		exit(-1);
	while(1)
	{
		clfd =  accept(serfd, NULL, NULL);
		switch(fork())
		{
			case -1:
				exit(-1);
			case 0:
				close(serfd);
				int comp = 0;
				int num = read(clfd, mes, sizeof(mes));
				
				if(num == 0)
				{
					printf("serve read 0\n");
					_exit(0);
				}
				if(num < 0)
				{
					printf("serve read error\n");
					_exit(-1);
				}
				printf("serve successly read %lu\n", num/sizeof(int));
				for(int i = 0; i < num/sizeof(int); ++i)
				{
					comp += mes[i];
					//printf("serve %d ", mes[i]);
				}
				printf("\nserve num: %d\n", comp);
				write(clfd, &comp, sizeof(int));
				_exit(0);
			default:
				close(clfd);
				break;
		}
	}
	return 0;
}

