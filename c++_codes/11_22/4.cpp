#include <iostream>

using namespace	std;

class		Shape
{
	public:
	virtual Shape * clone() const = 0;
};

class		Circle:	public Shape
{
	public:
	Circle * clone() const;
};

int 
main()
{
	return 0;
}
