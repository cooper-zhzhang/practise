#include <iostream>
using namespace std;

class A
{
public:
	A(int n)
	{
		value = n;
	}

	A(A other)
	{
		this->value = other.value;
	}

private:
	int value;
};

int main()
{
	A a = 10;
	A b = a;

	return 0;
}
