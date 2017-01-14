#include <stdio.h>

int sum(int x)
{
	if( x > 9)
		return 0;

	return x + sum(x + 1);
}

int main()
{
	int x;
	x = 1;
	printf("%d\n", sum(x));

	return 0;
}
