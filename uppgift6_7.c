#include <stdio.h>
#include <limits.h>

int rik(double vinst,double ranta,double perAr)
{
	int ar = 0;
	if (vinst*0.01*ranta >= perAr)
		return INT_MAX;
	else
	{
		while(1)
		{
			if ((vinst = vinst + vinst*0.01*ranta - perAr) < 0)
				break;
			ar++;
		}
		return ar;
	}
}

int main(void)
{
	double vinst,ranta,perAr;
	printf("Vinsten: ");
	scanf("%lf",&vinst);
	getchar();
	printf("Ränta: ");
	scanf("%lf",&ranta);
	getchar();
	printf("Uttag per år: ");
	scanf("%lf",&perAr);
	getchar();
	printf("Det håller i %d antal år.\n",rik(vinst,ranta,perAr));
	return 0;
}
