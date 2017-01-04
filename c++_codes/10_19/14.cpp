#include <iostream>

using namespace std;


int main()
{
	int array[99];
	int sum = 0;

	for(int i = 0; i < 100; ++i)
		sum += array[i];
	
	cout << 5050-sum << endl;

	return 0;
}
