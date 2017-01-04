#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
	}

	~Base()
	{
	}
};

int main()
{
	Base base;
	cout << sizeof(base) << endl;

	return 0;
}
