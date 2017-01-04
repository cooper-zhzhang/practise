#include <iostream>

using namespace std;


class Base
{
	// 行为
	public:
		void foo1(void){};
		void foo2(void){};
		// 属性
	public:
		double m_fMember1;
		int m_nMember2;
};


// 定义类成员函数指针类型
// 用于得到类的成员函数指针
typedef void (Base::*CLASS_FUNC)(void);

int main()
{
	// 创建一个Base类的对象
	Base base;
	// 输出类对象所在的地址
	cout <<"类占内存字节数是：" << sizeof(Base) << endl;
	cout<<"类对象的地址是："<<&base<<endl;
	// 输出类对象中成员变量的地址
	cout<<"类对象中成员变量m_fMember1的地址是："<<
		&(base.m_fMember1)<<endl;

	cout<<"类对象中成员变量m_fMember1占用的内存字节数是："<<
		sizeof(base.m_fMember1)<<endl;

	cout<<"类对象中成员变量m_nMember2的地址是："<<
		&(base.m_nMember2)<<endl;

	cout<<"类对象中成员变量m_fMember2占用的内存字节数是："<<
		sizeof(base.m_nMember2)<<endl;
	// 输出类中成员函数的地址

	// 第一个函数
	CLASS_FUNC pFunc = &Base::foo1;
	unsigned int* tmp =  (unsigned int*)&pFunc;
	cout << pFunc << endl;
	cout << &Base::foo1 << endl;
	cout<<"Base类第一个成员函数的地址是："<<hex<<*tmp<<endl;

	// 第二个函数
	pFunc = &Base::foo2;
	tmp =  (unsigned int*)&pFunc;
	cout << pFunc << endl;
	cout << &Base::foo2 << endl;
	cout<<"Base类第二个成员函数的地址是："<<hex<<*tmp<<endl;

	return 0;
}
