#include <stdio.h>

double sum(double f[],int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += f[i];
	return sum;
}

double kvad_sum(double f[],int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += f[i]*f[i];
	return sum;
}

void skriv_ut(double f[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%g ",f[i]);
}

int main(void)
{
	double f[] = {2.5,1.5,3.0};
	printf("Fältet: ");
	skriv_ut(f,3);
	printf("\nSumman av fältet: %g\nKvadrat summan av fältet: %g\n",sum(f,3),kvad_sum(f,3));
	return 0;
}
