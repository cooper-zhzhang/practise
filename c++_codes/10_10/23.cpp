#include <iostream>
using namespace std;

class Base
{
public:
	void f(int kk)
	{
		cout << kk << endl;
	}

};

int main()
{
	void (Base::*fun)(int);
	fun = &Base::f;
	Base base;
	(base.*fun)(43);
	return 0;
}
