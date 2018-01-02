#include <stdio.h>
#include <math.h>

void calc(double *values,int n,double *medel,double *standard)
{
	double sum = 0.0;
	/* Medelvärde. */
	for (double *p = values; p < values+n; p++)
		sum += *p;
	*medel = sum/(double)n;
	sum = 0.0;
	/* Standardavvikelse. */
	for (double *p = values; p < values+n; p++)
		sum += pow(*p-*medel,2);
	*standard = sqrt(sum/(double)n);
}

int main(void)
{
	double values[10] = {5.9,3.9,2.5,8.4,7.6,6.2,4.7,5.1,1.4,7.3},medel,standard;
	calc(values,10,&medel,&standard);
	printf("Medelvärdet: %g\nStandardavvikelsen: %g\n",medel,standard);
	return 0;
}
