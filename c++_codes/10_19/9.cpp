#include <iostream>

using namespace std;

class cla
{
	static int n;
	public:
	cla(){n++;};
	~cla(){n--;};
	static int getn()
	{
		return n;
	}
};
int cla::n = 0;

int main()
{
	cla *p = new cla;
	delete p;
	cout << cla::getn() << endl;
	return 0;
}
