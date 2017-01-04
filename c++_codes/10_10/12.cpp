#include <iostream>

using namespace std;

class Base
{
public:
	Base(int a)
	{
		this->a = a;
		cout << "构造函数" << endl;
	}
	Base(Base &b)
	{
		this->a = b.a;
		cout << "拷贝构造函数" << endl;
	}

	~Base()
	{
		cout << "析构函数" << endl;
	}
private:
	int a;
};

int main()
{
	Base b(1);
	Base b2 = b;
	return 0;
}


