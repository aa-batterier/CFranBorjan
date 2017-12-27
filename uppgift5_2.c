#include <stdio.h>

int main(void)
{
	int m,n,r;
	printf("Skriv in två heltal: ");
	scanf("%d%d",&m,&n);
	getchar();
	for(;;)
	{
		r = m % n;
		if (r == 0)
			break;
		else
		{
			m = n;
			n = r;
		}
	}
	printf("GCD = %d\n",n);
	return 0;
}
