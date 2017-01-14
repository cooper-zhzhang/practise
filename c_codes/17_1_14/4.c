#include <stdio.h>
#include <pthread.h>

void* fun(void *data_ptr)
{
	int *int_ptr = data_ptr;
	printf("%d\n", *int_ptr);
	return NULL;
}

int main(int argc, char **argv)
{

	int data = 11;
	int *int_ptr = &data;
	long *long_ptr = (long*) int_ptr;

	printf("%ld\n", *long_ptr);

	return 0;
}

