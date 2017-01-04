#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
	default_random_engine e;
	cout << e() << endl;
	cout << "e.max() " << endl;
	cout << hex << e.max() << endl;
	cout << e.max() << endl;
	short sun = e.max();
	cout << "short sun = e.max()" << endl;
	cout << hex << sun << endl;

	//¸ºÊýÌî³ä1
	unsigned int int_type = sun;
	cout << "unsigned int = sun" << endl;
	cout << dec << int_type << endl;
	cout << hex << int_type << endl;

	int_type = e.max();
	cout << "unsigned int = e.max() " << endl;
	cout << dec << int_type << endl;
	cout << hex << int_type << endl;
	
	double double_type = 4231435.8253465;
	cout << hex << double_type << endl;
	short sum = double_type;
	cout << hex << sum << endl;
	cout << dec << sum << endl;

	uniform_int_distribution<unsigned> u(0,9);
	for(size_t i = 0; i < 10; ++i)
		cout << u(e) << " ";
	return 0;
}

