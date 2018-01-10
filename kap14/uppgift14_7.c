#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int jrf(const void *p1,const void *p2)
{
	const double *q1 = p1,*q2 = p2;
	return *q1-*q2;
}

void list_sort(struct list *l,int(*jrf)(const void*,const void*))
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

int list_search(const void *sok,struct list *l,int(*jrf)(const void*,const void*))
{
	int i1 = 0,i2 = size(l)-1,m = 0;
	while (i1 <= i2)
	{
		m = (i1+i2)/2;
		if (jrf(sok,get(l,m)) < 0)
			i2 = m-1;
		else if (jrf(sok,get(l,m)) > 0)
			i1 = m+1;
		else
			break;
	}
	if (jrf(sok,get(l,m)) == 0)
		return m;
	return -1;
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
	for (;;)
	{
		printf("Sök efter: ");
		if (scanf("%lf",&tal) != 1)
			break;
		if (list_search(&tal,l,jrf) > 0)
			printf("Talet %g existerar i listan.\n",tal);
		else
			printf("Talet %g existerar inte i listan.\n",tal);
	}
	printf("\n");
	exit(0);
}
