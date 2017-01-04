#include <iostream>

using namespace std;

class A
{
	int a;
	int b;
};

class B : public A
{
	int a;
	virtual void f()
	{
		a++;
	}
	int b;
};

int main()
{
	A a, *Aptr;
	B b, *Bptr;

	Aptr = &a;
	Bptr = &b;
	Aptr = Bptr;

	cout << (Aptr == Bptr) << endl;
	void *ptr = Bptr;
	cout << (Aptr == ptr) << endl;

	cout << Aptr << endl;
	cout << Bptr << endl;
	return 0;
}
