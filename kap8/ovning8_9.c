#include <stdio.h>

double kol_sum(double f[][5],int antal_rader,int k)
{
	double sum = 0;
	for (int i = 0; i < antal_rader; i++)
		sum = sum + f[i][k];
	return sum;
}

int main(void)
{
	double f[4][5];
	/*for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			f[i][j] = 0.0;*/
	for (double i = 0,j = 1.0; i < 4; i++,j /= 10.0)
		f[(int)i][3] = j;
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%g\t",f[i][j]);
		printf("\n");
	}*/
	printf("%g\n",kol_sum(f,4,3));
	return 0;
}
