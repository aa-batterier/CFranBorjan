#include <stdio.h>
#include <math.h>

double upphoj(double x,double y)
{
	return exp(y*log(x));
}

int main(void)
{
	double x,y;
	printf("x? ");
	scanf("%lf",&x);
	getchar();
	printf("y? ");
	scanf("%lf",&y);
	printf("%e\n",upphoj(x,y));
	return 0;
}
