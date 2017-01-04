#include <iostream>

using namespace std;

int main()
{
	const int n = 100;
	int k;
	int array[n];

	array[1] = 1;
	array[2] = 1;
	
	for(int i = 3; i < n; ++i)
	{
		array[i] = array[i-1] + array[i-2];
	}

	cin >> k;
	cout << "jump to " << k << " having ";
	cout << array[k] << " methods" << endl;

	return 0;
}


