#include <stdio.h>

int main(void)
{
	int k;
	long long int p;
	printf("Skriv in ditt kön(flicka=0/pojke=1): ");
	scanf("%d",&k);
	getchar();
	printf("Skriv in ditt personnummer: ");
	scanf("%lld",&p);
	getchar();
	p /= 10;
	if ((k == 0 && p%2 == 0) || (k == 1 && p%2 == 1))
		printf("Stämmer.\n");
	else
		printf("Stämmer inte.\n");
	return 0;
}
