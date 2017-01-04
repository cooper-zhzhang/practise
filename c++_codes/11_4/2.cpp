#include <iostream>
using namespace std;

void fun(int x, int y)
{
	int sum;
	sum = x + y;
}

float fun(float x, float y)
{
	return x + y;
}

int main()
{
	int x = 1;
	int y = 2;
	int sum = fun(x, y);
	float u = 1.3;
	float v = 5.6;
	fun(u, v);

	return 0;
}
