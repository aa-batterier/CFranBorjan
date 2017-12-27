#include <stdio.h>
#include <math.h>

long long int nfak(int n)
{
	long long int i = 1;
	if (n == 0)
		return 1;
	else
		for (;n > 0; n--)
			i *= n;
	return i;
}

int mac(int x)
{
	int e = 1;
	for (int i = 1; i <= 7; i++)
		e += pow(x,i)/nfak(i);
	return e;
}

int main(void)
{
	int x;
	printf("Skriv in en exponent: ");
	scanf("%d",&x);
	printf("%d\n",mac(x));
	return 0;
}
