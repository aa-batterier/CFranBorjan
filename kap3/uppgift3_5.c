#include <stdio.h>
#include <math.h>

int main(void)
{
	double a,b,c,e,v;
	printf("Skriv in längden på sidan A: ");
	scanf("%lf",&a);
	getchar();
	printf("Skriv in längden på sidan B: ");
	scanf("%lf",&b);
	getchar();
	printf("Skriv in vinkeln mellan sidoran A och B: ");
	scanf("%lf",&v);
	getchar();
	e = 1e-10;
	v = v*2*M_PI/360;
	c = sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(v));
	if (fabs(a-b) < e && fabs(a-c) < e)
		printf("Triangeln är liksidig.\n");
	else if(fabs(a-b) < e || fabs(a-c) < e || fabs(b-c) < e)
		printf("Triangeln är likbent.\n");
	else
		printf("Triangeln är oliksidig."\n);
	return 0;
}
