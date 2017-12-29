#include <stdio.h>

void draw_line(int l)
{
	for (int i = 0; i < l; i++)
		printf("_");
	printf("\n");
}

int main(void)
{
	int l;
	printf("Skriv in hur lång rad: ");
	scanf("%d",&l);
	draw_line(l);
	return 0;
}
