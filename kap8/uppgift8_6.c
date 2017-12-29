#include <stdio.h>

void rotera(int f[],int n)
{
	int j = f[n-1];
	for (int i = n-1; i >= 0; i--)
	{
		if (i == 0)
			f[i] = j;
		else
			f[i] = f[i-1];
	}
}

void skriv_ut(int f[],int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ",f[i]);
}

int main(void)
{
	int f[] = {1,2,3,4,5};
	printf("Fältet: ");
	skriv_ut(f,5);
	rotera(f,5);
	printf("\nFältet roterat: ");
	skriv_ut(f,5);
	printf("\n");
	return 0;
}
