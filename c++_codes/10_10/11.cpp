#include <iostream>

using namespace std;

int main()
{
	int pi;
	int *pf, *&pref = pf;
	cout << typeid(pref).name() << endl;
	return 0;
}
