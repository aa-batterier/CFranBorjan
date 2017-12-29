#include <stdio.h>
#include <string.h>

int main(void)
{
	int a[100],b[20];
	for (int i = 0; i < 100; i++)
		a[i] = i;
	memset(b,0,sizeof(b));
	for (int i = 0; i <= 4; i++)
	{
		b[i+10] = a[i+50];
		b[i+5] = a[i+95];
	}
	for (int i = 0; i < 20; i++)
		printf("%d\t%d\n",i,b[i]);
	//printf("\n");
	return 0;
}
