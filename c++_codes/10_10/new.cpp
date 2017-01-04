#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int *ptr;
	for(i = 0; i < 9999999999L; ++i)
	{
		try
		{
			ptr = new int(1);
			cout << "++" << endl;
		}
		catch(runtime_error mess)
		{
			cout << mess.what() << endl;
			exit(-1);
		}
	}
	cout << "fuck" << endl;

	return 0;
}
