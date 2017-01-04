#include <iostream>

using namespace std;

class A
{
	int data;

public:

static	void *operator new(size_t size)
	{
		std::cout << "new " << std::endl;
		std::cout << size << std::endl;
		return malloc(size);
	}

	A(int x):data(x){}
	static void f()
	{
		std::cout << "xdf" << std::endl;
	}

};

void * operator new(size_t size)
{
	cout << size << endl;
	return malloc(size);
}

int main(int argc, char **argv)
{
	A a(1);
	A *APtr = new A(2); 

	delete(APtr);

	return 0;
}
