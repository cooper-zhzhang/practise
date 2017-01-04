#include <iostream>

using namespace std;

void gene(int aga[])
{
	cout << sizeof(aga) << endl;
}

int main()
{
	int a[10];
	gene(a);

	return 0;
}


