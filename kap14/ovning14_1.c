#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
	struct list *ls = new_list();
	double tal,storst = 0;
	int n = 0;
	printf("Skriv in tal:\n");
	while (scanf("%lf",&tal) == 1)
	{
		double *p = (double*)malloc(sizeof(double)*1);
		*p = tal;
		add_last(ls,p);
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		double *p = get(ls,i);
		if (*p > storst)
			storst = *p;
	}
	printf("Största talet i listan är %g.\n",storst);
	exit(0);
}
