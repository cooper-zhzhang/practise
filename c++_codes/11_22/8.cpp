#include <iostream>

using namespace std;

class A
{
	int C;
	int b;
public:
void destory()
{
	delete this;
}
private:
	~A()
	{
		//free(this);
	}
};

int main()
{
	std::cout << sizeof(A) << std::endl;

  A *ptr = new A;
	ptr->destory();

	return 0;
}
