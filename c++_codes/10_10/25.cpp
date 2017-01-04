#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string str("sdfgh");
	unique_ptr<string> p1(new string("dsfd"));
	unique_ptr<string> p2(p1);
	return 0;
}
