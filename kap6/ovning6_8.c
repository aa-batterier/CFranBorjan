#include <stdio.h>

long long int nfak(int);

int main(void)
{
	int n;
	printf("n?: ");
	scanf("%d",&n);
	printf("%lld\n",nfak(n));
	return 0;
}

long long int nfak(int n)
{
	long long int i = 1;
	if (n == 0)
		return 1;
	for (;n > 0; n--)
		i *= n;
	return i;
}
