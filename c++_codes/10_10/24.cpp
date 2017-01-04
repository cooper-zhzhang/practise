#include <iostream>

using namespace std;

int main()
{
	shared_ptr<int> ptr(new int(32));
	cout << *ptr << endl;

	shared_ptr<int> pt = make_shared<int>(2);
	cout << *pt << endl;
	shared_ptr<int> pt2 = pt;



	return 0;
}
