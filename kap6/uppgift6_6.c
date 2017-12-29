#include <stdio.h>

long long int nfak(int n)
{
	long long int i = 1;
	if (n == 0)
		return 1;
	for (;n > 0; n--)
		i *= n;
	return i;
}

int binomial(int n,int k)
{
	return nfak(n)/(nfak(k)*nfak(n-k))+0.5;
}

int main(void)
{
	int n,k;
	printf("n?: ");
	scanf("%d",&n);
	getchar();
	printf("k?: ");
	scanf("%d",&k);
	getchar();
	printf("%d\n",binomial(n,k));
	return 0;
}
