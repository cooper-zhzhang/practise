#include <iostream>

using namespace std;

int main()
{
	int i = 100;
	int k = 0;
	while(i)
	{
		i++;

	if(k == 0)
		k = 1;
	else if(k == 1)
		k = 10;
	else if(k == 10)
		k = 50;
	else if(k == 50)
		k = 100;
	else if(k >= 100 && k < 1000)
		k += 100;
	else if(k >= 1000 && k < 10000)
		k += 1000;
	else
		break;
	
	cout << "@Test" << endl;
	cout << "public void test" << i << "_update() { "<< endl;
	cout << "long s1 = System.currentTimeMillis();" << endl;
	cout << " int i = " << k << ";" << endl;
	cout << "while(i-->0) testService.findUserById(userId);" << endl;
	cout << "long s2 = System.currentTimeMillis();" << endl;
	cout << "System.out.println(\"test " << k << "更新耗时:\" + (s2 - s1));" << endl;
	cout << "++ userId;" << endl;
	cout << "}" << endl;
	cout << endl;

	if(k == 10000)
		break;
	}


	return 0;
}

