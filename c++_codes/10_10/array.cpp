#include <array>
#include <iostream>

using namespace std;

int main()
{
	array<int, 10> arr;
	cout << arr.at(10);

	cout << "++" << endl;

	return 0;
}
