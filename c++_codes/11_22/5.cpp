#include <iostream>

using namespace std;

class NoHeap
{
	public:

	protected:
	void *operator new(size_t) {
		return 0;
	}

	void operator delete(void *) {
		return 0}

};

int main()
{

	return 0;
}
