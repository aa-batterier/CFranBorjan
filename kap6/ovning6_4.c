#include <stdio.h>

double read_double(void)
{
	double x;
	scanf("%lf",&x);
	return x;
}

int read_int(void)
{
	int n;
	scanf("%d",&n);
	return n;
}

double upphojt_till(double x, int n)
{
	double res = 1;
	int i = 1;
	if (n >= 0)
		for (;i <= n; i++)
			res = res*x;
	else
		for (;i <= -n; i++)
			res = res/x;
	return res;
}

int main(void)
{
	double xx;
	int nn;
	printf("x? ");
	xx = read_double();
	printf("n? ");
	nn = read_int();
	printf("Resultat: %g.\n",upphojt_till(xx,nn));
	return 0;
}
