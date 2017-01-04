#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	a = 10;
	printf("%d %d %d\n", ++a, a++, a);

	return 0;
}
