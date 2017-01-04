#include <stdio.h>
int increment(int* p) 
{ 
	return (*p)++; 
}
	
int main(void)
{
	 int i = 0;
	 int a[] = {1,1};
	 a[i] = increment(&i);
	 printf("%d %d\n", a[0], a[1]);
   printf("%d %d %d\n", i, a[0], a[1]);

	 return 0;
}
