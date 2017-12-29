#include <stdio.h>

int main(void)
{
	int n,summa = 0;
	printf("n? ");
	scanf("%d",&n);
	getchar();
	for (int k = 1; k <= n; k++)
		summa += k;
	printf("Summa blir %d\n",summa);
}
