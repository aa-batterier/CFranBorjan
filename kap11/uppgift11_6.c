#include <stdio.h>

void min_and_max(double *f,int n,double *min,double *max)
{
	*min = *f;
	*max = *f;
	for (double *p = f; p < f+n; p++)
	{
		if (*min > *p)
			*min = *p;
		if (*max < *p)
			*max = *p;
	}
}

int main(void)
{
	double d[] = {5.43,7.3,5.7,3.2,1.6,4.7},min,max;
	min_and_max(d,6,&min,&max);
	printf("Minst: %g\nStörst: %g\n",min,max);
	return 0;
}
