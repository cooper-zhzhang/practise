#include <iostream>

using namespace std;

class A
{
public:
	virtual void fun()
	{
		cout << "Class A" << endl;
	}
};

class B : public A
{
public :
	virtual void fun()
	{
		cout << "Class B " << endl;
	}
};

int main()
{
	A *p = new A();
	p->A::fun();

	p->fun();
//	p->B::fun(); ´íÎó class A do not have fun function
	return 0;
}
