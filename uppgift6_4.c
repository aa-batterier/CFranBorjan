#include <stdio.h>

#define MOMS 25.0
#define ARB_AVG 28.97
#define STAT_LAG 0.0
#define STAT_MEDEL 20.0
#define STAT_HOG 25.0
#define LAG 1
#define MEDEL 2
#define HOG 3

double skatt(double inkomst,double kommun,int nivo)
{
	double procent,lon,total,inkmoms;
	if (nivo == LAG)
		procent = kommun + STAT_LAG;
	else if (nivo == MEDEL)
		procent = kommun + STAT_MEDEL;
	else
		procent = kommun + STAT_HOG;
	lon = inkomst/(1-0.01*procent);
	total = lon + lon*0.01*ARB_AVG;
	inkmoms = total + total*0.01*MOMS;
	return inkmoms;
}

int main(void)
{
	int nivo;
	double inkomst,kommun;
	printf("Skriv in önskad inkomst: ");
	scanf("%lf",&inkomst);
	getchar();
	printf("Skriv in kommunalskatten: ");
	scanf("%lf",&kommun);
	getchar();
	printf("Skriv in skatte nivån: ");
	scanf("%d",&nivo);
	getchar();
	printf("Din avgift blir %g.\n",skatt(inkomst,kommun,nivo));
	return 0;
}
