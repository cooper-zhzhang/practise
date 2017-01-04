#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	bitset<8> bit;
	bit.set();

	cout << bit.to_string() << endl;
	bit[0] = 0;
	cout << bit.to_string() << endl;
	bit.reset();
	cout << bit.to_string() << endl;
	bit.set();
	cout << bit.to_string() << endl;

	int i = 1;
	int k = 6;
	int j = 7;
	printf("%.*f\n", j, (float)i/k);


	return 0;
}
