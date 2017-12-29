#include <stdio.h>

#define N 10
#define T 10000.0

_Bool ar_sorterat(double f[],int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			if (f[i] < f[j])
				return 0;
			else
				continue;
		}
	return 1;
}

int main(void)
{
	int i = 0;
	double f[N];
	for (int j = 0; j < N; j++)
		f[j] = T;
	while (scanf("%lf",&f[i]) == 1)
		i++;
	if (ar_sorterat(f,N))
		printf("Fältet är sorterat.\n");
	else
		printf("Fältet är inte sorterat.\n");
	return 0;
}
