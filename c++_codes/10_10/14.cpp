#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	for(int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	auto it = s.begin(); 
	for(;it != s.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "endl" << endl;

	for(it = s.begin(); it != s.end(); )
	{
		if(*it == 3 || *it == 4)
		{
			s.erase(it++);
		}
		else
			++it;
	}
	it = s.begin();

	for(;it != s.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}

