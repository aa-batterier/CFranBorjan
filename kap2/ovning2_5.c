#include <stdio.h>

#define PI 3.141592653589793

int main(void)
{
	double r=5,omkr=2*PI*r,area=PI*r*r;
	printf("Radie = %.3f.\nOmkrets = %.3f.\nArea = %.3f.\n",r,omkr,area);
	return 0;
}
