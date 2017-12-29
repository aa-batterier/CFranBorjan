#include <stdio.h>

int main(void)
{
	int a,b;
	printf("Skriv in två heltal: ");
	scanf("%d %d",&a,&b);
	printf("Deras summa är %d.\nDeras skillnad är %d.\n",a+b,a-b);
	return 0;
}
