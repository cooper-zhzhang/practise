#include <deque>
#include <cstdio>
#include <algorithm>
using namespace	std;
int
main()
{
	deque < int    >ideq(20);
	deque < int    >::iterator pos;
	int		i;

	for (i = 0; i < 20; ++i)
		ideq[i] = i;

	printf("输出deque中数据:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	printf("\n在头尾加入新数据...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%p \n", (int*)&(*pos));
	putchar('\n');

	return 0;
}
