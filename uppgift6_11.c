#include <stdio.h>
#include <math.h>

double rot(double x)
{
	double g = x / 2;
	while(1)
	{
		if (g*(x/g) == x)
			return g;
		else if (fabs(g-x/g) < 1e-6)
			return g;
		else
			g = (g+x/g)/2;
	}
}

int main(void)
{
	double x;
	printf("Roten ur: ");
	scanf("%lf",&x);
	printf("%lf\n",rot(x));
	return 0;
}
