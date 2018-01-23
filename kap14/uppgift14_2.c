#include <stdio.h>
#include <stdlib.h>
#include "list.h"

_Bool ar_sorterat(struct list *l)
{
	for (int i = 1; i < size(l); i++)
	{
		double *p0 = get(l,i-1),*p1 = get(l,i);
		if (*p0 > *p1)
			return 0;
	}
	return 1;
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
	if (ar_sorterat(l))
		printf("Fältet är sorterat.\n");
	else
		printf("Fältet är inte sorterat.\n");
	exit(0);
}
