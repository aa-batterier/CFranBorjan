#include <stdio.h>

int main(void)
{
	double array1[] = {0.0,0.0,0.0,0.0};
	int array2[] = {5,10,20,50,100,200,500};
	for (int i = 0; i < sizeof(array1)/sizeof(array1[0]); i++)
		printf("%.3lf ",array1[i]);
	printf("\n");
	for (int i = 0; i < sizeof(array2)/sizeof(array2[0]); i++)
		printf("%d ",array2[i]);
	printf("\n");
	return 0;
}
