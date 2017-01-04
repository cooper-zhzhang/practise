#include <iostream>

using namespace std;

class A
{
public:
	void test()
	{
		printf("dsf");
	}
};

int main()
{
	A *ptr = NULL;
	ptr->test();

	return 0;
}
