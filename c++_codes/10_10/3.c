#include <stdio.h>

void fun(int x)
{
	int *ptr = &x;
	while(ptr)
	{
		printf("%x\n", *ptr);
		ptr ++;
	}
}


int main()
{
	printf("fun %x\n", &fun);
	fun(2);
	return 0;
}
