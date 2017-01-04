#include <iostream>
using namespace std;

void fun(int x, char *ch)
{
	cout << "ads";
}

int main()
{
	void (*fp)(int, char*);
	fp = fun;
	(*fp)(1, "adsf");
	return 0;
}
