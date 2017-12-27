#include <stdio.h>

void multi(int tal)
{
	for (int i = 1; i <= tal; i++)
		printf("%d\t%d\n",i,i*tal);
}

int main(void)
{
	int tal;
	printf("Skriv in ett heltal: ");
	scanf("%d",&tal);
	multi(tal);
	return 0;
}
