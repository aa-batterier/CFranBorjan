#include <stdio.h>

#define N 4

_Bool magisk(int f[][N],int r)
{
	if (N != r)
		return 0;
	int sum_r[N],sum_k[N],sum_d[2];
	for (int i = 0; i < N; i++)
	{
		sum_r[i] = 0;
		sum_k[i] = 0;
		sum_d[i] = 0;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			sum_r[i] += f[i][j];
			sum_k[i] += f[j][i];
		}
	for (int i = 0,j = 0; i < N; i++,j++)
		sum_d[0] += f[i][j];
	for (int i = 0,j = N-1; i < N; i++,j--)
		sum_d[1] += f[i][j];
	if (sum_d[0] != sum_d[1])
		return 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			if (sum_r[i] != sum_r[j] || sum_k[i] != sum_k[j])
				return 0;
		}
	for (int i = 0; i < N; i++)
		if (sum_r[i] != sum_k[i] || sum_r[i] != sum_d[0] || sum_r[i] != sum_d[1] || sum_k[i] != sum_d[0] || sum_k[i] != sum_d[1])
			return 0;
	return 1;
}

void test_f(int f[][N],int r)
{
	if (magisk(f,r))
		printf("är magiskt.\n");
	else
		printf("är inte magiskt.\n");
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
	/* Ett exempel på en magisk fyrkant.
	int f_m[N][N] = {{16,9,2,7},
			{6,3,12,13},
			{11,14,5,4},
			{1,8,15,10}};*/
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
