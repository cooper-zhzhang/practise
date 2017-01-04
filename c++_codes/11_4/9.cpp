#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool less_(char& x, char& y)
{
	return x > y;
}

int main()
{
	string str = "qwertyuiopasdfghjklzxcvbnm";
	sort(str.begin(), str.end(), less_);
	cout << str << endl;

	return 0;
}
