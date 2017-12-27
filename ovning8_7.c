#include <stdio.h>
#include <string.h>

void fyll(double f[],int min,int max,double v)
{
	for (int i = 0; i <= max-min; i++)
		f[i+min] = v;
}

int main(void)
{
	double f[20];
	memset(f,0,sizeof(f));
	fyll(f,7,16,3.12);
	for (int i = 0; i < 20; i++)
		printf("%d\t%g\n",i,f[i]);
	return 0;
}
