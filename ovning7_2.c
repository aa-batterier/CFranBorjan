#include "ovning7_2.h" 

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

void new_lines(int n)
{
	for (int i = 1; i <= n; i++)
		printf("\n");
}
