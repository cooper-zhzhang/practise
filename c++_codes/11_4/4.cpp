#include <iostream>

using namespace std;

class A
{
public:
	int a;
	int b;
};

int main()
{
	int A::*ptr;
	ptr = &A::a;
	cout << ptr << endl;
	int *p = reinterpret_cast<int*>(0x32);
	cout << sizeof(void *) << endl;
	void *pp;
	cout << pp << endl;
	A obj;
	cout << &(obj.a) << endl;
	return 0;
}
