#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int color,value;
}kort;

void init_kort(kort kortlek[])
{
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= 13; j++)
		{
			kortlek[k] = (kort){i,j};
			k++;
		}
}

void blanda(kort kortlek[])
{
	srand((int)time(NULL));
	int slumpKort1 = rand()%52,slumpKort2 = rand()%52;
	kort tempKort = kortlek[slumpKort1];
	kortlek[slumpKort1] = kortlek[slumpKort2];
	kortlek[slumpKort2] = tempKort;
}

int main(void)
{
	kort kortlek[52];
	init_kort(kortlek);
	for (int i = 0; i < 137; i++)
		blanda(kortlek);
	int start = 0;
	while (start < 52)
	{
		printf("Antal kort: ");
		int antal;
		if (scanf("%d",&antal) != 1 || antal == 0 || antal > 52)
			break;
		for (int i = start; i < antal; i++)
			printf("Kort %d:\nFärg: %d\nVärde: %d\n\n",i,kortlek[i].color,kortlek[i].value);
		start += antal;
	}
	return 0;
}
