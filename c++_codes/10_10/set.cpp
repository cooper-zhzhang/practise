#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
	set<int> se;
	se.insert(1);
	se.insert(2);
	
	auto it = se.cbegin();
	se.insert(it, 4);
	
	se.insert({5, 2, 3, 4, 5, 6, 7, 8});
	it = se.begin();
	for(; it != se.end(); ++it)
		cout << *it << " ";
	cout << endl;
	for(it = se.begin(); it != se.end(); )
	{
		if(*it == 5)
		{
			it = se.erase(it);
		}
		else
			++it;
	}

	for(it = se.begin(); it != se.end(); ++it)
		cout << *it << " ";
	return 0;
}
