#include <iostream>

using namespace std;

struct A
{
	int a;
	int b;
	short c;
};

int main()
{
	cout << sizeof(A) << endl;

	return 0;
}

