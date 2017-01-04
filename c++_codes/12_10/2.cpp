#include <iostream>

using namespace std;

int main()
{
	//unsigned long long count = 10000000000;
	size_t count = 10000000000;
	bitset<count> bit;
	bit.reset();
	unsigned long long data;
	while(count --> 0)
	{
		cin >> data;
		if(bit[data] == 1)
		{
			cout << data << endl;
			break;
		}
		bit[data] = 1;
	}

	return 0;
}

