#include <iostream>
#include <cstdio>

using namespace std;

char* getmomery()
{
	char p[] = "hello, world";
	return p;
}

int main()
{

	char *str = NULL;
	str = getmomery();
	printf(str);
	return 0;
}
