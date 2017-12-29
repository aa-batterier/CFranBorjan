#include <stdio.h>

int main(void)
{
	double array[10];
	for (int i = 0; i < 10; i++)
		array[i] = 1.0/(double)(i+1);
	for (int i = 0; i < 10; i++)
		printf("%lf ",array[i]);
	printf("\n");
	return 0;
}
