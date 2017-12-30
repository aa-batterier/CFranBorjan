#include <stdio.h>
#include <math.h>

double calculate_vector(double *v,int n)
{
	double sum = 0.0;
	for (double *p = v; p < v+n; p++)
		sum += pow(*p,2);
	return sqrt(sum);
}

int main(void)
{
	double vector[] = {5,3,1};
	printf("Summan av vektorn (5,3,1) är %g.\n",calculate_vector(vector,3));
	return 0;
}
