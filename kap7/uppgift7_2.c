#include <stdio.h>

static int i = 1;
static int j = 1;

void fib(void)
{
	j = j + i;
	i = j - i;
}

int main(void)
{
	for (int k = 0; k < 20; k++)
	{
		fib();
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}
