#include <iostream>
#include "pthread.h"

using namespace std;

void* fun(void * argc) 
{
}

int main()
{
	pthread_t tid;
	time_t time_1, time_2;
	time_1 = time(NULL);
	pthread_create(&tid, NULL, &fun, NULL);
	pthread_join(tid, NULL);
	time_2 = time(NULL);
	cout << time_2 << endl << time_1 << endl;
	cout << time_2 - time_1 << endl;
	return 0;
}
