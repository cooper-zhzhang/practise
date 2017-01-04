#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a = 1;
	int b = 3;
	int i = -1;
	while(i++<106)
		printf("%d: %s\n", i, strerror(i));
	return 0;
}
