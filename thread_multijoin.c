//���ϵ�Դ������bug�����̺߳������ݲ���ʱ�����õ�ָ�룬���ǲ�֪�������ĵ�����Σ�ָ����ָ��Ļ������ᱻ�ı�
//�������ڸ�����վ�����������
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

static pthread_cond_t thread_died = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t thread_mutex = PTHREAD_MUTEX_INITIALIZER;

static int tot_threads = 0;
static int num_live = 0;

static int num_unjoined = 0;

enum tstate
{
	TS_ALIVE,
	TS_TERMINATED,
	TS_JOINED
};

static struct 
{
	pthread_t tid;
	enum tstate state;
	int sleep_time;
} *thread;

static void* thread_func(void *arg)
{
	uintptr_t idx = (uintptr_t)arg;
	//int idx = ((int)arg);
//	int idx = *((int*)arg);
	int s;
	sleep(thread[idx].sleep_time);
	printf("Thread %lu terminating\n", idx);

	s = pthread_mutex_lock(&thread_mutex);
	if(s != 0)
		exit(-1);
	
	num_unjoined++;
	thread[idx].state = TS_TERMINATED;

	s = pthread_mutex_unlock(&thread_mutex);
	if(s != 0)
		exit(-1);
	s = pthread_cond_signal(&thread_died);
	if(s != 0)
		exit(-1);
	

	printf("Thread %lu exit\n", idx);
	return NULL;
}

int main(int argc, char **argv)
{
	int s, idx;
	thread = calloc(argc - 1, sizeof(*thread));
	if(thread == NULL)
		exit(-1);
	
	for(idx = 0; idx < argc - 1; ++idx)
	{
		thread[idx].sleep_time = atoi(argv[idx+1]);
		thread[idx].state = TS_ALIVE;
	//	s = pthread_create(&thread[idx].tid, NULL, thread_func, &idx);
	//	s = pthread_create(&thread[idx].tid, NULL, thread_func, ((void*)idx));
		s = pthread_create(&thread[idx].tid, NULL, thread_func, ((void*)(uintptr_t)idx));
		if(s != 0)
			exit(-1);
	}

	tot_threads = argc - 1;
	num_live = tot_threads;

	while(num_live > 0)
	{
		s = pthread_mutex_lock(&thread_mutex);
		if(s != 0)
			exit(-1);
		while(num_unjoined == 0)
		{
			s = pthread_cond_wait(&thread_died, &thread_mutex);
			if(s != 0)
				exit(-1);
		}

		for(idx = 0; idx < tot_threads; ++idx)
		{
			if(thread[idx].state == TS_TERMINATED)
			{
				s = pthread_join(thread[idx].tid, NULL);
				if(s != 0)
					exit(-1);
				thread[idx].state = TS_JOINED;
				--num_live;
				--num_unjoined;

				printf("reaped thread %d (num_live=%d)\n", idx, num_live);
			}
		}
		s = pthread_mutex_unlock(&thread_mutex);
		if(s != 0)
			exit(-1);
	}
	return 0;
}

