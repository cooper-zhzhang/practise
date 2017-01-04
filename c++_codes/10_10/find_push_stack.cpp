#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main()
{
	list<int> ex;
	list<int> check;
	stack<int> sta;
	
	int m;
	int n;
	int k;
	int count;

	cin >> count;
	n = count;
	while(n--)
	{
		cin >> k;
		ex.push_back(k);
	}

	n = count;
	while(n--)
	{
		cin >> k;
		check.push_back(k);
	}
	while(1)
	{
		if(!sta.empty() && ex.empty())
		{
			cout << "no" << endl;
			exit(-1);
		}
		if(sta.empty() && ex.empty())
		{
			cout << "success" << endl;
		}

		k = check.front();
		check.pop_front();

		m = ex.front();
		if(k == m)
		{
			ex.pop_front();
		}
		else
		{
			if(!sta.empty())
			{
			if(k == sta.top())//Õ»¶¥
			{
				//³ö
				sta.pop();
			}
			else
			{
				//ÈëÕ»
				sta.push(k);
			}
			}
		}
	}

	return 0;
}

