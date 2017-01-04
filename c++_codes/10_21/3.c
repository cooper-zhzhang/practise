#include <stdio.h>

int main()
{
	unsigned x;
	unsigned short y;
	y = 0xffff;
	printf("%x\n", y);
	x = y;
	x = 0xffffffff;
	int value = x;
	printf("%x\n", value);
	printf("%d\n", value);

	char uv = -3;
	unsigned char tv = uv;
	printf("%uc\n", tv);
	short xx = -13;
	unsigned int xxx = xx;
	printf("%u\n", xxx);

	return 0;
}
