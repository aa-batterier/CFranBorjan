#include <stdio.h>

#define R 10
#define K 5

void skriv_ut(int f[][K],int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < K; j++)
			printf("%d\t",f[i][j]);
		printf("\n");
	}
}

void aendra(int f[][K],int r)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < 5; j++)
			f[i][j] = i+j;
}

int main(void)
{
	int a[R][K];
	aendra(a,R);
	skriv_ut(a,R);
	return 0;
}
