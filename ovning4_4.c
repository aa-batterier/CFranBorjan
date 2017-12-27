#include <stdio.h>

int main(void)
{
	double m;
	while (1)
	{
		int i = 0;
		if (m < 0)
			break;
		printf("Meter från marken: ");
		scanf("%lf",&m);
		getchar();
		while(m > 0.01)
		{
			m = m-(m*0.3);
			i++;
		}
		printf("%d gånger.\n",i);
	}
	return 0;
}
