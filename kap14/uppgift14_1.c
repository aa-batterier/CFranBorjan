#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(void)
{
	struct list *l = new_list();
	double tal,*first;
	int n = 0;
	printf("Skriv in tal:\n");
	while (scanf("%lf",&tal) == 1)
	{
		double *p = (double*)malloc(sizeof(double));
		*p = tal;
		add_last(l,p);
		n++;
	}
	if (n != 0)
	{
		first = get(l,0);
		printf("\n%g ",*first);
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++)
			{
				double *pI = get(l,i),*pJ = get(l,j);
				if (*pI == *pJ)
					break;
				else if (i == j+1)
					printf("%g ",*pI);
				else
					continue;
			}
	}
	printf("\n");
	exit(0);
}
