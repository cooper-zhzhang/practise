#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> map3;
	map<int, int>::iterator it_map;

	for(int i = 0; i < 2000000; ++i)
	{
		map3.insert(make_pair(i, i));
	}

	for(it_map = map3.begin(); it_map != map3.end(); )
	{
		if(it_map->second % 2 == 0)
		{
			it_map = map3.erase(it_map);
		}
		else
			++it_map;
	}
	cout << map3.size() << endl;

	return 0;
}
