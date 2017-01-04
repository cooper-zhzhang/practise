#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> li;
	for(int i = 0; i < 10; ++i)
		li.push_front(i);
	auto it = li.begin();
	for(; it != li.end(); ++it)
		cout << *it << endl;
	cout << "endl" << endl;
	it = li.begin();
	for(; it != li.end(); ++it)
	{
		if(*it == 3 || *it == 4)
		{
			li.erase(it);
		}
	}

	it = li.begin();
	for(; it != li.end(); ++it)
		cout << *it << endl;

	return 0;
}
