#include <iostream>

using namespace std;

int main()
{
	function<int(int)> fun= [&](int n)->int{ return n == 1 ? 1 : n*fun(n-1); };

	cout << fun(12)  << endl;;

	return 0;
}


