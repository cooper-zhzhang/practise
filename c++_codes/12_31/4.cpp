#include <iostream>

int main()
{
	int a = 11;
	int &&b = std::move(a);

	std::cout << b << std::endl;
	a = 14;
	std::cout << b << std::endl;
	std::cout << (&a == &b) << std::endl;

	return 0;
}
