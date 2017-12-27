#include <stdio.h>

int main(void)
{
	long int p;
	printf("Skriv in ett postnummer: ");
	scanf("%ld",&p);
	getchar();
	p /= 1000;
	if ((p >= 20 && p <= 62) || p == 65 || p == 66)
		printf("Postnummret ligger i Götaland.\n");
	else if (p >= 80)
		printf("Postnummret ligger i Norrland.\n");
	else
		printf("Postnummret ligger i Svealand.\n");
	return 0;
}
