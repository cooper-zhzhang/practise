#include <stdio.h>

int main()
{
	short x = 12345;
	short mx = -x;

	unsigned char *ptr;
	ptr = (char*)&x;
	for(size_t i = 0; i < sizeof(short); ++i)
	{
		printf("%x", *ptr);
		++ptr;
	}
	printf("\n");
	ptr = (char*)&mx;
	for(size_t i = 0; i < sizeof(short); ++i)
	{
		printf("%x", *ptr);
		++ptr;
	}

	return 0;
}


