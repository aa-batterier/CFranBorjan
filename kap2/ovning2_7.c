#include <stdio.h>

int main(void)
{
	int l,b;
	printf("Skriv in rektangelns längd och bredd: ");
	scanf("%d%d",&l,&b);
	printf("Rektangelns omrekts är %d.\nRektangelns area är %d.\n",l*2+b*2,l*b);
	return 0;
}
