#include <iostream>

using namespace std;
//1查找函数名
//2选择最佳的匹配函数
//3检查是否具有访问权限

class B
{
public:
	void f(double dou)
	{
		cout << dou << endl;
	}
};

class D : public B
{
	void f(int in)
	{
		cout << in << endl;
	}
	
public:
	void f(float fl)
	{
		cout << fl << endl;
	}
};

int main()
{
	D d;
	d.B::f(12.3);
	//在子类中找到了函数，选取最佳的匹配，由于函数是私有的，调用失败
	d.f(1);
	d.f(12.4);

	return 0;
}
