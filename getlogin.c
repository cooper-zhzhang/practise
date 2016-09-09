#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char *name;
	name = getlogin();
	printf("%s\n", name);
	return 0;
}

