#include <iostream>
#include <pthread.h>

void* fun(void *args)
{
	std::cout << gettid() << std::endl;
	return args;
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, fun, NULL);
	std::cout << t1 << std::endl;
	pthread_join(t1, NULL);

	pthread_create(&t2, NULL, fun, NULL);
	std::cout << t2 << std::endl;
	pthread_join(t2, NULL);


	return 0;
}
