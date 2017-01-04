#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[20000] = { 0 };
	int n;
	cin >> n;
	int i = 0;
	long long sum = 0;
	for(i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n -1);
	long long count = 0;
	for(i = n - 1; i > 0 ; --i)
	{
		count += sum;
		sum -= a[i];
	}
	
	cout << count << endl;
	return 0;
}
