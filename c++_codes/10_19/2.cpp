#include <iostream>

using namespace std;

struct test
{
	int size;
	char data[0];
};

int main()
{
	test *t;
	t = (test*)malloc(sizeof(test) + 100);
	t->data[2] = '2';
	cout << t->data[2] <<endl;
	cout << sizeof(*t) << endl;
	cout << &(t->size) << endl;
	cout << &(t->data) << endl;

	return 0;
}
