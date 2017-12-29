#include <stdio.h>

int main(void)
{
	int i = 0;
	double m;
	printf("Meter från marken: ");
	scanf("%lf",&m);
	getchar();
	while(m > 0.01)
	{
		m = m-(m*0.3);
		i++;
	}
	printf("%d gånger.\n",i);
	return 0;
}
