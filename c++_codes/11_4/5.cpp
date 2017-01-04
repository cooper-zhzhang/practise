#include <iostream>

using namespace std;

int main()
{
	char ch[100];
	cin >> ch;
	cout << ch << endl;
	cout << static_cast<int>(ch[0]) << endl;

	return 0;
}
