#include <stdio.h>

_Bool ar_kvinna(long long int nr)
{
	nr /= 10;
	return nr % 2 == 0;
}

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
	if ((k == 0 && ar_kvinna(p)) || (k == 1 && !ar_kvinna(p)))
		printf("Stämmer.\n");
	else
		printf("Stämmer inte.\n");
	return 0;
}
