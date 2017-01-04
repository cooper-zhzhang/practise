#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char *ptr;
	printf("%x\n", ptr);
	ptr = "wewertrytgfsdsa";
	cout << strlen(ptr) << endl;
	cout << sizeof(ptr) << endl;
	printf("%x\n", ptr);
	return 0;
}
