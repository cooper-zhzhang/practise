#include <iostream>

int main(int argc, char **argv)
{
	int a = 1;
	int &&b = ::std::move(a);

	::std::cout << &b << ::std::endl;
	::std::cout << &a << ::std::endl;

	::std::cout << b << ::std::endl;
	a = 11;
	::std::cout << b << ::std::endl;

	int &&c = 12;
	::std::cout << c << ::std::endl;

	return 0;
}
