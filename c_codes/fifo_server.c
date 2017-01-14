#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define SERVER_FIFO "/tmp/seqnum_sv"
#define CLIENT_FIFO_TEMPLATE "/tem/seqnum_cl.%ld"

#define CLIENT_FIFO_NAME_LEN (sizeof(CLIENT_FIFO_TEMPLATE) + 20)

struct request
{
	pid_t pid;
	int seqlen;
};

struct response
{
	int seqnum;
};

int main(int argc, char **argv)
{
	int serverfd, dummpyfd, clientfd;
	char clientfifo[CLIENT_FIFO_NAME_LEN];
	struct request req;
	struct response resp;
	int seqnum = 0;
	umask(0);
	if(mkfifo(SERVER_FIFO, S_IRUSR | S_IWUSR | S_IWGRP) == -1 && errno != EEXIST)
		exit(-1);
	serverfd = open(SERVER_FIFO, O_RDONLY);
	if(serverfd == -1)
		exit(-1);
	dummpyfd = open(SERVER_FIFO, O_WRONLY);
	if(dummpyfd == -1)
		exit(-1);
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		exit(-1);
	for(;;)
	{
		if(read(serverfd, &req, sizeof(struct request)) != sizeof(struct request))
		{
			printf("read error\n");
			continue;
		}

		snprintf(clientfifo, CLIENT_FIFO_NAME_LEN, CLIENT_FIFO_TEMPLATE, (long)req.pid);
		clientfd = open(clientfifo, O_WRONLY);
		if(clientfd == -1)
		{
			printf("open %s error\n", clientfifo);
			continue;
		}

		resp.seqnum = seqnum;
		if(write(clientfd, &resp, sizeof(struct response)) != sizeof(struct response))
			printf("error\n");
		if(close(clientfd) == -1)
			printf("error\n");
		seqnum += req.seqlen;
	}
}

