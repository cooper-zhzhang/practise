#include <iostream>

using namespace std;

int main()
{
	const int value = 12;
	//const int *x = &value;
	const int *x = 123;
	int *y = const_cast<int *>(x);

	*y = 321;

	cout << value << " " << &value << endl;
	cout << *y << " " << y << endl;
	cout << *x << " " << x << endl;

	return 0;
}
	
