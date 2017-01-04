#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> li = {1, 3, 4, 5, 5, 6, 7, 8};

	auto it = li.begin();
	for(; it != li.end(); ++it)
		cout << *it << " ";
	for(it = li.begin(); *it != 3; ++it);
	li.insert(it, 2);
	for(it = li.begin(); it != li.end();)
	{
		if(*it == 5)
		 it = li.erase(it);
		else
			++it;
	}
	cout << endl;
	for(it = li.begin(); it != li.end(); ++it)
		cout << *it << " ";
	
	cout << endl;
//不是随机迭代器
//	sort(li.begin(), li.end());

		return 0;
}
