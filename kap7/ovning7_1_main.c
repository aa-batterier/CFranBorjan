#include <stdio.h>

long long int nfak(int n);

int main(void)
{
	int n;
	printf("n?: ");
	scanf("%d",&n);
	printf("%lld\n",nfak(n));
	return 0;
}
