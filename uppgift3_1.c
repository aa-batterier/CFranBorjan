#include <stdio.h>

int main(void)
{
	int m;
	printf("Skriv in antal minuter du kommer att ringa per månad: ");
	scanf("%d",&m);
	getchar();
	if (m >= 66)
		printf("Det lönar sig mest att ta abonemanget Plus.\n");
	else if (66 > m && m >= 33)
		printf("Det lönar sig mest att ta abonemanget Normal.\n");
	else
		printf("Det lönar sig mest att ta abonemanget Kontant.\n");
	return 0;
}
