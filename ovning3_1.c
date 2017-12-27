#include <stdio.h>

int main(int argc, char **argv)
{
	double m,k;
	printf("Skriv in antal minuter per månad: ");
	scanf("%lf",&m);
	getchar();
	printf("Skriv in kostnaden per minut: ");
	scanf("%lf",&k);
	getchar();
	if (m + k >= 1000)
		printf("Kostnaden är %g.\n",(m+k)-((m+k)*0.10));
	else
		printf("Kostnaden är %g.\n",m+k);
	return 0;
}
