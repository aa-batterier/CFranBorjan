#include <stdio.h>
#include <stdlib.h>
#include "list.h"

double jrf(const void *p1,const void *p2)
{
	const double *q1 = p1,*q2 = p2;
	return *q1-*q2;
}

void list_sort(struct list *l,double(*jrf)(const void*,const void*))
{
	for (int i = 0; i < size(l); i++)
	{
		int m = i;
		for (int j = i+1; j < size(l); j++)
			if (jrf(get(l,j),get(l,m)) < 0)
				m = j;
		double *temp = get(l,i);
		set(l,i,get(l,m));
		set(l,m,temp);
	}
}

int main(void)
{
	struct list *l = new_list();
	double tal;
	printf("Skriv in tal:\n");
	while (scanf("%lf",&tal) == 1)
	{
		double *p = (double*)malloc(sizeof(double));
		*p = tal;
		add_last(l,p);
	}
	list_sort(l,jrf);
	for (int i = 0; i < size(l); i++)
	{
		double *p = get(l,i);
		printf("%g ",*p);
	}
	printf("\n");
	exit(0);
}
