#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> m;
	map<int, int> m2;
	int a;
	int n, k;
	cin >> n >>k;
	int i = 0;
	for(i = 0; i < n; ++i)
	{
		cin >> a;
		m.insert({a, i});
	}
	
	int count = 0;
		
	for(auto it = m.begin(); it != m.end(); ++it)
	{
		if(count >= k)
			break;
		count++;
		
		m2.insert({it->second, it->first});
	}
	m.clear();

	for(auto it = m2.begin(); it != m2.end(); ++it)
	{
		cout << it->second << endl;
	}

	return 0;

}
