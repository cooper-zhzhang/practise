#include <iostream>

using namespace std;

int main()
{
	int n[][3] = {10, 20, 30, 40, 50, 60};
	int (*p)[3];
	p = n;
	cout << (p[1]+1)[1] << endl;
	return 0;
}
