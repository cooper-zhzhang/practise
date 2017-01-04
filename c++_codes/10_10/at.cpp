#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 10> arry;
	try
	{
		cout << arry.at(10);
	}
	catch(out_of_range mess)
	{
		cout << mess.what() << endl;
	}

	cout << "C++" << endl;
	
	return 0;
}
