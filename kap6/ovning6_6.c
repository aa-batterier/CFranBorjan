#include <stdio.h>

_Bool ar_skottar(int ar)
{
	return (ar % 4 == 0 && ar % 100 != 0) || ar % 400 == 0;
}

int main(void)
{
	int ar;
	printf("Skriv ett årtal: ");
	scanf("%d",&ar);
	if (ar_skottar(ar))
		printf("Skottår\n");
	else
		printf("Inte skåttår\n");
}
