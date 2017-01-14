#include <stdio.h>

void first_prin(int *data, int index)
{
	if(index >= 4)
	{
		printf("\n");
		return;
	}
	printf("%d ", data[index]);
	first_prin(data, index+1);
}

void last_prin(int *data, int index)
{
	if(index >= 4)
	{
		return;
	}

	last_prin(data, index+1);
	printf("%d ", data[index]);
}

void sum(int *data)
{
	long sum = 0;
	int i = 0;
	for(;i < 4; ++i)
		sum += data[i];
	printf("\n%ld\n", sum);
}

int main()
{
	int data[4];
	int i = 0;
	for(;i < 4; ++i)
		scanf("%d", data + i);
	first_prin(data, 0);
	last_prin(data, 0);
	sum(data);

	return 0;
}
