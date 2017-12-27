#include <stdio.h>

int main(void)
{
	double l,b,t;
	printf("Skriv in brevets längd: ");
	scanf("%lf",&l);
	getchar();
	printf("Skriv in brevets bredd: ");
	scanf("%lf",&b);
	getchar();
	printf("Skriv in brevets tjocklek: ");
	scanf("%lf",&t);
	getchar();
	if (l > 600 || l < 140 || b < 90 || t > 100 || l+b+t > 900)
		printf("Felaktiga mått.\n");
	else
		printf("Måtten OK.\n");
	return 0;
}
