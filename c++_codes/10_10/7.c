#include <stdio.h>

struct s
{
	int i;
	int j;
	char c;
};

int main()
{
	printf("%u\n", sizeof(struct s));

	return 0;
}
