#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<function<void()>> vec;

	for(size_t i = 0; i < 10; ++i)
	{
		const int m = i;
		auto action = [&] { cout << m << endl; };
		vec.push_back(action);
	}

	for(auto & var : vec)
	{
		var();
	}


	int x = 2;
	int y = 3;
	cout << &x << endl;
	auto fun = [=]{cout << &x << endl;};
	fun();

	auto fun1 = [&] { cout << &x << endl;};
	fun1();
	return 0;
}

