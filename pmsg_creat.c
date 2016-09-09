#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int flags, opt;
	mode_t perms;
	mqd_t mqd;
	struct mq_attr attr, *attrp;
	mq_unlink("/mq");

	attrp = NULL;
	attr.mq_maxmsg = 50;
	attr.mq_msgsize = 2048;
	flags = O_RDWR;

	while((opt = getopt(argc, argv, "cm:s:x")) != -1)
	{
		switch(opt)
		{
			case 'c':
				flags |= O_CREAT;
				break;
			case 'm':
				attr.mq_maxmsg = atoi(optarg);
				attrp = &attr;
				break;
			case 's':
				attr.mq_msgsize = atoi(optarg);
				attrp = &attr;
				break;

			case 'x':
				flags |= O_EXCL;
				break;
			default:
				exit(-1);
		}
	}
	if(optind >= argc)
		exit(-1);
	
	perms = (argc <= optind + 1) ? (S_IRUSR | S_IWUSR) : atoi(argv[optind]);
	mqd = mq_open(argv[optind], flags, perms, attrp);
	if(mqd == (mqd_t)-1)
		exit(-1);
	if(mq_getattr(mqd, &attr) == -1)
		exit(-1);
	printf("max of message on queue: %ld\n", attr.mq_maxmsg);
	printf("max of message size: %ld\n", attr.mq_msgsize);

	mq_send(mqd, argv[optind+1], strlen(argv[optind+1]), 0);



	return 0;
}
