#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Popless : public std::binary_function<char, char, bool>
{
public :
	bool operator ()(const char &x, const char &y) const
	{
		return x < y;
	}
};

int main()
{
	string str = "qwertyuioplkjhgfdsazxcvbnm";
	sort(str.begin(), str.end(), Popless());
	cout << str << endl;
	string str1 = "qwertyuioplkjhgfdsazxcvbnm";
	sort(str1.begin(), str1.end(), *(new Popless()));
	cout << str1 << endl;
	string str2 = "qwertyuioplkjhgfdsazxcvbnm";
	Popless popless;
	sort(str2.begin(), str2.end(), popless);
	cout << str1 << endl;

	return 0;
}
