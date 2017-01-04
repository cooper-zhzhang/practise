#include <iostream>

using namespace std;

int main()
{
	float x = 121324.5435645;
	cout << x << endl;
	int  i = *(int*)&x;
	cout << i << endl;

	return 0;
}
