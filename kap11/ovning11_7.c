#include <stdio.h>
#include <math.h>

_Bool equal(const double *rad1,const double *sist,const double *rad2,_Bool (*f)(double,double))
{
	for (const double *p = rad1; p < sist; p++,rad2++)
		if (!f(*p,*rad2))
			return 0;
	return 1;
}

_Bool nastan_lika(double one,double two)
{
	if (one-two < 1.0e-10)
		return 1;
	return 0;
}

int main(void)
{
	double a1[] = {1.3,4.89,3.21,893.43,4.0,8.78},a2[] = {4.5,3.0,2.90,23.4,4.4,5.32},a3[] = {1.3,4.89,3.21,893.43,4.0,8.78};
	if (equal(a1,a1+6,a2,nastan_lika))
		printf("a1 och a2 är lika.\n");
	else
		printf("a1 och a2 är inte lika.\n");
	if (equal(a1,a1+6,a3,nastan_lika))
		printf("a1 och a3 är lika.\n");
	else
		printf("a1 och a3 är inte lika.\n");
	return 0;
}
