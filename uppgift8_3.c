#include <stdio.h>

void min_memcpy(double f1[],double f2[],int b)
{
	for (int i = 0; i < b; i++)
		f1[i] = f2[i];
}

void skriv_ut(double f[],int a)
{
	for (int i = 0; i < a; i++)
		printf("%g ",f[i]);
}

int main(void)
{
	double f1[] = {1.0,2.1,4.2,3.1},f2[] = {4.5,6.7,3.4,9.0};
	printf("f1: ");
	skriv_ut(f1,4);
	printf("\nf2: ");
	skriv_ut(f2,4);
	min_memcpy(f1,f2,2);
	printf("\nf1 2b: ");
	skriv_ut(f1,4);
	min_memcpy(f1,f2,4);
	printf("\nf1 4b: ");
	skriv_ut(f1,4);
	printf("\n");
	return 0;
}
