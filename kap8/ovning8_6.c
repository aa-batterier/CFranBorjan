#include <stdio.h>

#define N 100

double medel(double pris[], int antal)
{
	double sum = 0;
	for (int i = 0; i < antal; i++)
		sum += pris[i];
	return sum/antal;
}

int main(void)
{
	double pris[N];
	int n = 0;
	while (n < N)
	{
		printf("Pris/min för kort nr %d? ",n+1);
		if (scanf("%lf",&pris[n]) != 1)
			break;
		n++;
	}
	int billigast = 0;
	for (int i = 1; i < n; i++)
	{
		if (pris[i] < pris[billigast])
			billigast = i;
	}
	printf("\nKort nr %d är billigast.\n",billigast+1);
	printf("Kostnad: %4.2f kr/minut",pris[billigast]);
	printf("\nMedelvärdet för priserna är %d\n",medel(pris,N));
	return 0;
}
