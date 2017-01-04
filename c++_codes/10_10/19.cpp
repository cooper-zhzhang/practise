//实现cpp share_ptr
//不考虑多线程安全
#include <iostream>

using namespace std;

template <typename T>
class Base
{
public:
	T print()
	{
		cout << "use = " << *use << endl;
		return *data;
	}

	Base(const T *data)
	{
		this->data = data;
		use = new T;
		*use = 1;
	}
	
	Base()
	{
		data = new T{};
		use = new int;
		*use = 1;
	}

	Base(const Base &b)
	{
		this->data = b.data;
		this->use = b.use;
		(*use) ++;
	}

	~Base()
	{
		if(--(*use) <= 0)
		{
			delete data;
			delete use;
		}
	}

	T& operator *()
	{
		return *data;
	}

	Base<int>& operator = (T data)
	{
		*(this->data) = data;
		return *this;
	}

	Base<int>& operator = (const Base &b)
	{
		if(&b == this)
			return *this;
		this->data = b.data;
		this->use = b.use;
		++ (*use);
		return *this;
	}

private:
	int *use;
	T *data;
};

int main()
{
	/*
	Base<int> base(new int(4));
	cout << *base << endl;
	int *ptr = new int;
	*ptr = 8;
	Base<int> b(ptr);
	*base = 1;
	cout << *base << endl;
	base = b;
	cout << b.print() << endl;
	cout << base.print() << endl;
	*/
	Base<int> bbk;
	cout << *bbk << endl;
	Base<int> b;
	b = bbk;
	//cout << *base << endl;
	return 0;
}
