#include <stdio.h>

#define PI 3.141592653589793

int main(void)
{
	double r;
	printf("Skriv in radien för en cirkel: ");
	scanf("%lf",&r);
	printf("Radie = %.3f.\nOmkrets = %.3f.\nArea = %.3f.\n",r,2*PI*r,PI*r*r);
	return 0;
}
