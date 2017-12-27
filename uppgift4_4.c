#include <stdio.h>

int main(void)
{
	int r;
	printf("Skriv in antal rader som ska visas: ");
	scanf("%d",&r);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%d\t",i*j);
		printf("\n");
	}
	return 0;
}
