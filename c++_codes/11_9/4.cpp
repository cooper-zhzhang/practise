#include <iostream>

using namespace std;
//1���Һ�����
//2ѡ����ѵ�ƥ�亯��
//3����Ƿ���з���Ȩ��

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
	//���������ҵ��˺�����ѡȡ��ѵ�ƥ�䣬���ں�����˽�еģ�����ʧ��
	d.f(1);
	d.f(12.4);

	return 0;
}
