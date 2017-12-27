#include <stdio.h>

int main(void)
{
	double i,j = 1.0,s = 0;
	printf("Skriv in ett heltal: ");
	scanf("%lf",&i);
	getchar();
	while (j <= i)
	{
		s += 1.0/j;
		j++;
	}
	printf("Summan blev %g.\n",s);
	return 0;
}
