#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	short int a = 0X102;

	char *ptr = (char*)&a;

	if(*(ptr+1) == 0X1)
		cout << "small" << endl;
	else
		cout << "great" << endl;

	return 0;
}
	
