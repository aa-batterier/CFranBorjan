#include <stdio.h>

int main (void)
{
	_Bool s = 1;
	int f[50],i = 1; 
	f[0] = 2;
	for (int j = 3; i < 50; j++)
	{
		for (int k = 0; k < i; k++)
		{
			if (j%f[k] == 0)
			{
				s = 0;
				break;
			}
		}
		if (s)
		{
			f[i] = j;
			i++;
		}
		s = 1;
	}
	for (int i = 0; i < 50; i++)
		printf("%d ",f[i]);
	printf("\n");
	return 0;
}
