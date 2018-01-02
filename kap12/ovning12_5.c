#include <stdio.h>
#include "person.h"

void las_person(struct person *p)
{
	printf("Förnamn? ");
	scanf("%s",p->fornamn);
	printf("Efternamn? ");
	scanf("%s",p->efternamn);
	printf("Födelseår? ");
	scanf("%d",&p->fodd_ar);
	printf("Singel? ");
	char svar[10];
	scanf("%s",svar);
	if (svar[0] == 'j' || svar[0] == 'J')
		p->singel = 1;
	else
		p->singel = 0;
}

void skriv_person(struct person *p)
{
	printf("%s %s, född år %d, är ",p->fornamn,p->efternamn,p->fodd_ar);
	if (p->singel)
		printf("singel.\n");
	else
		printf("inte singel.\n");
}

int main(void)
{
	struct person p;
	las_person(&p);
	skriv_person(&p);
	return 0;
}
