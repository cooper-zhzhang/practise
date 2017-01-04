#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int>m;
	for(int i = 0; i < 6; ++i)
	{
		m.insert({i, i + 1});
	}
	m[6]++;
	auto it = m.begin();
	for(; it != m.end(); ++it)
	{
		cout << it->first << " ";
		cout << it->second << endl;
	}
	it = m.begin();
	for(; it != m.end(); )
	{
		if(it->second == 2 || it->second == 1)
		{
			auto k = it;
			m.erase(it++);
		}
		else
			it++;
	}

	it = m.begin();
	for(; it != m.end(); ++it)
	{
		cout << it->first << " ";
		cout << it->second << endl;
	}

	
	return 0;
}
