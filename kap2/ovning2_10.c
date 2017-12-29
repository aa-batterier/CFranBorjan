#include <stdio.h>
#include <math.h>

int main(void)
{
	int d,h = 0;
	printf("Temperaturen:\nMåndag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Tisdag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Onsdag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Torsdag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Fredag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Lördag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Söndag: ");
	scanf("%d",&d);
	getchar();
	h = fmax(h,d);
	printf("Högsta temperaturen under veckan var %d grader.\n",h);
	return 0;
}
