#include <stdio.h>
#include <string.h>

#define T 1000

int main(void)
{
	int f[T];
	memset(f,0,sizeof(f));
	for (int i = 0; i < T; i++)
		if (scanf("%d",&f[i]) != 1)
			break;
	printf("\n%d ",f[0]);
	for (int i = 1; i < T; i++)
		for (int j = 0; j < i; j++)
		{
			if (f[i] == f[j])
				break;
			else if (i == j+1)
				printf("%d ",f[i]);
			else
				continue;
		}
	printf("\n");
	return 0;
}
