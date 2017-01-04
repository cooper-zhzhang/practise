#include <iostream>

typedef union
{
	long i;
	int k[5];
	char c;
}date;
struct data
{
	int cat;
	date cow;
	double dog;
} too;

date max;

int main()
{
	std::cout << sizeof(data) << std::endl;
	std::cout <<  sizeof(max);
	return 0;
}

