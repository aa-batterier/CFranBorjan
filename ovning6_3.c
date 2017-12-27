#include <stdio.h>

int main(void)
{
	int i,j=0;
	printf("Skriv in ett heltal: ");
	scanf("%d",&i);
	while (i > 0)
	{
		i /= 10;
		j++;
	}
	printf("%d antal siffor.\n",j);
	return 0;
}
