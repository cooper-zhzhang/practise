#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> li;
	for(int i = 10; i > 0; --i)
		li.push_back(i);

	
	sort(li.begin(), li.end());
	
	
	auto it = li.begin();
	for(it; it != li.end(); ++it)
		cout << *it << " ";

	cout << endl;


	return 0;
}

