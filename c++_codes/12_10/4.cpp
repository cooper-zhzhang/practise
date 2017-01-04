#include <iostream>
 
 using namespace std;


 int fun(int x)
 { 
	 x <= 100 && (cout << x, fun(++x)); 
	 return x;
 }
 
 int main()
 {
	 int x = 1;
	 fun(x);

	 return 0;
 }
