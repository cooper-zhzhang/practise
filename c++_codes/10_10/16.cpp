#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> que;
	for(int i = 0; i < 15; ++i)
		que.push(i);
	while(!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	return 0;
}
//front size empty push pop
//same like stack
