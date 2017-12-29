#include <stdio.h>

int main(void)
{
	int a,i = 1,j = 1;
	printf("Skriv in ett heltal: ");
	scanf("%d",&a);
	getchar();
	while(j*j <= a*a)
	{
		i += j*j;
		j++;
	}
	printf("Summan är %d\n",i);
	return 0;
}
