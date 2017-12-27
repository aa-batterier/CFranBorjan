#include <stdio.h>

int main(void)
{
	int ar,antal = 26000;
	printf("Skriv in år: ");
	scanf("%d",&ar);
	for (int i = 2016; i <= ar; i++)
		antal += 300-325+antal*(0.7-0.6)/100+0.5;
	printf("Befolking: %d.\n",antal);
	return 0;
}
