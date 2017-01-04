#include <iostream>

using namespace std;

int main()
{
	const int con_in = 3;
	const int *pt = & con_in;
	//*pt = 20;
	int *p = const_cast<int*>(pt);
	*p = 21;
	cout << con_in << endl;

	cout << typeid(10).name() << endl;
	return 0;
}
