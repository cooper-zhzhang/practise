#include <iostream>

int read(int &&a)
{
	a++;
	std::cout << &a << std::endl;
	delete (&a);
	return a;
}

int main()
{
	int a = 0;
	int *ptr = new int(0);
	int b = read(std::move(*ptr));
	std::cout << "called read() " << std::endl;
	delete ptr;
	ptr = nullptr;

	return 0;
}

