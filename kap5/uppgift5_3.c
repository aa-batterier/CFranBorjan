#include <stdio.h>

int main(void)
{
	int tal,i = 1;
	printf("Skriv in ett heltal: ");
	scanf("%d",&tal);
	while (i <= tal)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tal % i != 0)
				printf("%d ",i);
			i++;
		}
		printf("\n");
	}
	return 0;
}
