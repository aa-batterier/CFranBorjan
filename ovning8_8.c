#include <stdio.h>

int main(void)
{
	int f[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			f[i][j] = (i+1)*(j+1);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d\t",f[i][j]);
		printf("\n");
	}
	return 0;
}
