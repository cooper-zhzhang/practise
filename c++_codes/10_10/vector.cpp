#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ve;
	for(int i = 0; i < 10; ++i)
		ve.push_back(i);
	auto it = ve.begin();
	
	for(;it != ve.end();++it)
	{
		if(*it == 1 || *it == 2)
		{
			ve.erase(it);
			it--;
		}
	}
	for(it = ve.begin(); it != ve.cend(); ++it)
		cout << *it << endl;

	return 0;
}
