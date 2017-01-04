#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;
	m.insert({1, "sdf"});
	cout << m[1] << endl;
	m[1] = "sss";
	cout << m[1] << endl;
	return 0;
}

