#include <iostream>

using namespace std;

int compare(int x, int y)
{
	return x + y;
}

/*
int compare(int x, int y)
{
	return x + y;
}
*/

double compare(double x, double y)
{
	return x + y;
}

int main()
{
	double sum = compare(3, 4.0f);
	return 0;
}
