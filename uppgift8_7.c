#include <stdio.h>
#include <math.h>

double sum_f(double f[],int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += f[i];
	return sum;
}

double kvad_f_sum(double f[],int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += pow(f[i],2);
	return sum;
}

double sigma(double x[],int n)
{
	return sqrt((kvad_f_sum(x,n)-(1/n)*pow(sum_f(x,n),2))/(n-1));
}

int main(void)
{
	double x[] = {1.2,3.6,7.9,1.9,7.4,3.8},s = sigma(x,sizeof(x)/sizeof(x[0]));
	printf("Fältet: ");
	for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
		printf("%g ",x[i]);
	printf("\nStandardavikelse: %g\n",s);
	return 0;
}
