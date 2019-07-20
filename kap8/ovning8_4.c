#include <stdio.h>

int main(void)
{
	int n = 0,k = 1;
	double p1,p2 = 100000;
	while (1)
	{
		printf("Pris/min för kort nr %d? ", n+1);
		if (scanf("%le",&p1) != 1)
			break;
		if (p2 > p1)
		{
			p2 = p1;
			k = n;
		}
		n++;
	}
	printf("Kort nr %d är billigast.\nKostnad: %4.2f kr/minut",k,p2);
	return 0;
}
