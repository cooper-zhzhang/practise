#include <iostream>

using namespace std;

class Account
{
public:
	static const int a;
	int out()
	{
		return a;
	}
	static int out(int x);
};

const int Account::a = 11;

int Account::out(int x)
{
	return x + a;
}

int main()
{
	Account account;
	cout << account.out();
	cout << endl;
	cout << account.out(2);
	cout << endl;
	cout << Account::out(3);

	return 0;
}
