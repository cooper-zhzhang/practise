#include <iostream>

using namespace std;

int main()
{
	const static int sum = 0;
	
	int *p = (int*)(&sum);
	*p = 10;
	cout << sum << endl;

	return 0;
}


