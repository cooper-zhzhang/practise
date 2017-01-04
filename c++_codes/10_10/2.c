#include <stdio.h>

short uadd_ok(unsigned short x,unsigned short y)
{
	unsigned short sum;
	sum = x + y;
	if(sum < x || sum < y)
		return 0;
	else
		return 1;
}

int main()
{
	unsigned short x = 0xf;
	unsigned short y = 0xfff0;
	short flag = uadd_ok(x, y);
	printf("%d\n", flag);
	return 0;
}

