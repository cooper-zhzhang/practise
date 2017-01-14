#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> sp(new int[10], [](int *p) { delete [] p; });
	sp.reset();

	return 0;
}
