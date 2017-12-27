#include <stdio.h>

int main(void)
{
	int j = 0;
	for (double i = 0.01; i <= 10000000.0; i += i)
		j++;
	printf("%d dagar.\n",j);
	return 0;
}
