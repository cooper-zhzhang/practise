#include <iostream>

using namespace std;

int main()
{
	long long time[22] = {0};
	int i = 22;
	int size = 22;
	int times = 0;
	int k = 0;
	cin >> times;
	while(times-->0)
	for(i = 0; i < size; ++i)
	{
		cin >> k;
		time[i] += k;
	}

	for(long long & elm : time)
		cout << elm << endl;

	return 0;
}
