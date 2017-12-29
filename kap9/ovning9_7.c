#include <stdio.h>
#include <string.h>

int main(void)
{
	char p1[11],p2[11];
	printf("Skriv in dina första sex siffror i ditt personnummer: ");
	scanf("%s",p1);
	printf("Nästa person, skriv in dina sex första siffror i ditt personnummer: ");
	scanf("%s",p2);
	if (strncmp(p1+2,p2+2,4) == 0)
		printf("Ni har födelsedag på samma dag.\n");
	else
		printf("Ni har inte födelsedag på samma dag.\n");
	return 0;
}
