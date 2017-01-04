#include <iostream>

class Handle
{
public:
	Handle()
	{
		std::cout << "Handle construct " << std::endl;
	}

	void * operator new(size_t)
	{
		std::cout << "new" << std::endl;
		return 0;
	}

	void operator delete(void *)
	{
		std::cout << "delete" << std::endl;
	}

private:
	int a;
};

int main()
{
	Handle *handlePtr = new Handle;
	std::cout << handlePtr << std::endl;
	delete handlePtr;

	return 0;
}
