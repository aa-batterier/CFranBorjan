#include <stdio.h>

_Bool perfekt(int tal)
{
	int sum = 0;
	for (int i = 1; i < tal; i++)
		if (tal % i == 0)
			sum += i;
	return sum == tal;
}

int main(void)
{
	int tal;
	printf("Skriv in ett tal: ");
	scanf("%d",&tal);
	getchar();
	if (perfekt(tal))
		printf("Talet är perfekt.\n");
	else
		printf("Talet är inte perfekt.\n");
	return 0;
}
