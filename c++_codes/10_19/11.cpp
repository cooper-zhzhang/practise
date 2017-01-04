#include <iostream>

using namespace std;

void add(int a, int b)
{
	cout << "add_int_int " << endl;
	int sum = a + b;
}

void add(double a, double b)
{
	cout << "add_double_double " << endl;
	double sun = a + b;
}


int main()
{
	cout << typeid(234.4536f).name() << endl;
	float a = 0.23;
	float b = 3.45;
	add(a, b);

	return 0;
}
