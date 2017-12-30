#include <stdio.h>

void skriv_ut(int *f,int n)
{
	for (int *p = f; p < f+n; p++)
		printf("%d ",*p);
	printf("\n");
}

int main(void)
{
	int f[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	skriv_ut(f,16);
	return 0;
}
