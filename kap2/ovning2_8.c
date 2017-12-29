#include <stdio.h>

int main(void)
{
	int p,ms,e,m;
	printf("Skriv in varans pris inkulsive moms och momssatsen: ");
	scanf("%d%d",&p,&ms);
	e = p/(1+0.01*ms);
	m = p - e;
	printf("Varans pris exklusive moms är %d.\nMomsen på varan är %d.\n",e,m);
	return 0;
}
