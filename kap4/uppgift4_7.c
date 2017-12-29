#include <stdio.h>

int main(void)
{
	int domare,svarighet,poang,sum = 0;
	printf("Antal domare: ");
	scanf("%d",&domare);
	getchar();
	if (domare < 3)
		return 1;
	while (1)
	{
		printf("Hoppets svårighetsgrad: ");
		if (scanf("%d",&svarighet) != 1)
			return 1;
		getchar();
		printf("Poäng:\n");
		for (int i = 0; i < domare; i++)
		{
			if (scanf("%d",&poang) != 1)
				return 1;
			getchar();
			sum += poang;
		}
		sum = (sum/domare)*3*svarighet;
		printf("Poängen blir %d\n",sum);
	}
	return 0;
}
