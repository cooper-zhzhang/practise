#include <iostream>
#include <stdexcept>

using namespace std;

void fun(int *ptr, int *opr)
{
	if(ptr == opr)
	{
		throw runtime_error("pointer is same");
	}
	else
	{
	int t = *ptr;
	*ptr = *opr;
	*opr = t;
	}
}


int main()
{
	int a = 1;
	int b = 2;
	int *ptr2;
	int *ptr1;
	ptr2 = &a;
	ptr1 = &a;
 	try
	{
		fun(ptr2, ptr1);
	}
	catch(runtime_error mess)
	{
		cout << mess.what() << endl;
	}
	catch(exception mess)
	{
		cout << mess.what() << endl;
	}
	catch(range_error mess)
	{
		cout << mess.what() << endl;
	}
	catch(overflow_error mess)
	{
		cout << mess.what() << endl;
	}

	return 0;
}

