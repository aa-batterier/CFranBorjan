#include <stdio.h>

void bubble_sort(double a[],int start,int slut)
{
	int flag;
	do
	{
		flag = 0;
		for (int i = start; i < slut; i++)
			if (a[i] > a[i+1])
			{
				double temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				flag = 1;
			}
	}while(flag);
}

void skriv_ut(double a[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%g ",a[i]);
	printf("\n");
}

int main(void)
{
	double a[] = {34.65,56.4,23.09,93.12,42.9,67.8,11.49,89.54};
	skriv_ut(a,8);
	bubble_sort(a,0,7);
	skriv_ut(a,8);
	return 0;
}
