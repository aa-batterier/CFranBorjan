#include <stdio.h>

#define N 4

_Bool symmetrisk(int f[][N],int r)
{
	if (N != r)
		return 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < N; j++)
			if (f[i][j] != f[j][i])
				return 0;
	return 1;
}

void test_f(int f[][N],int r)
{
	if (symmetrisk(f,r))
		printf("är symmetriskt.\n");
	else
		printf("är inte symmetriskt.\n");
}

void skriv_ut(int f[][N],int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
}

int main(void)
{
	/*int f1[][N] = {{0,1,0,1},
		       {1,0,1,0},
		       {0,1,0,1},
		       {1,0,1,0}};
	int f2[][N] = {{0,1,1,0},
		       {1,1,1,0},
		       {0,0,1,0},
		       {1,0,0,1}};
	printf("Fält 1: ");
	test_f(f1,N);
	printf("Fält 2: ");
	test_f(f2,N);*/
	int c,f[N][N],v[4];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			f[i][j] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int vi = 0;
			while(1)
			{
				if ((c = getchar()) == ' ' || c == '\n' || c == EOF)
					break;
				else
				{
					v[vi] = c - '0';
					vi++;
				}
			}
			for (int k = vi-1,m = 1; k >= 0; k--, m *= 10)
				f[i][j] += v[k]*m;
		}
	}
	printf("\n");
	skriv_ut(f,N);
	printf("Fältet ");
	test_f(f,N);
	return 0;
}
