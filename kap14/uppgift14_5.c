#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

typedef struct
{
	int color,value;
}kort;

void init_kort(struct list *kortlek)
{
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= 13; j++)
		{
			kort *nyttKort = (kort*)malloc(sizeof(kort));
			*nyttKort = (kort){i,j};
			add_last(kortlek,nyttKort);
		}
}

void blanda(struct list *kortlek)
{
	int slumpKort1 = rand()%52,slumpKort2 = rand()%52;
	kort *tempKort = get(kortlek,slumpKort1);
	set(kortlek,slumpKort1,get(kortlek,slumpKort2));
	set(kortlek,slumpKort2,tempKort);
}

int main(void)
{
	srand((int)time(NULL));
	struct list *kortlek = new_list();
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
		for (int i = start; i < antal+start && i < 52; i++)
		{
			kort *k = remove_first(kortlek);
			printf("Kort %d:\nFärg: %d\nVärde: %d\n\n",i,k->color,k->value);
		}
		start += antal;
	}
	exit(0);
}
