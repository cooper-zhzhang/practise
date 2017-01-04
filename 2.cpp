#include <iostream>

using namespace std;

class Base
{
public:
	int data;
	int name;
};

int main()
{
	Base base;
	int Base::*dataPtr;
	dataPtr = &Base::data;

	cout << dataPtr << endl;
	cout << base.*dataPtr << endl;
	dataPtr = (int Base::*)0x2;
	cout << base.*dataPtr << endl;

	return 0;
}

