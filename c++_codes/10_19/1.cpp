#include <iostream>

class Base
{
private:
	int a;
	static int b;

public:
	Base(int x, int y): a(x)
	{
	}
	static void setB(int y) 
	{
		b = y;
	}
	void set() const
	{
		int a;
		this->a = a++;
	}

};


int main()
{
	Base base(1, 2);


	return 0;
}
