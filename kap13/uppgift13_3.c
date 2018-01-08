#include <stdio.h>

void insertion_sort(double a[],int start,int slut)
{
	for (int i = start+1; i <= slut; i++)
		for (int j = i; j >= start; j--)
			if (a[j] < a[j-1])
			{
				double tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
}

void skriv_ut(double a[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%g ",a[i]);
	printf("\n");
}

int main(void)
{
	double a[] = {7.042,1.558,5.619,2.449,3.999,4.512,6.343,0.932};
	skriv_ut(a,8);
	insertion_sort(a,0,7);
	skriv_ut(a,8);
	return 0;
}
