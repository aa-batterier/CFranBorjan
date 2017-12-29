#include <stdio.h>

#define PI 3.141592653589793

double omkrets(double r)
{
	return 2*PI*r;
}

double area(double r)
{
	return PI*r*r;
}

int main(void)
{
	double r;
	printf("Skriv in radien för en cirkel: ");
	scanf("%lf",&r);
	printf("Radie = %.3f.\nOmkrets = %.3f.\nArea = %.3f.\n",r,omkrets(r),area(r));
	return 0;
}
