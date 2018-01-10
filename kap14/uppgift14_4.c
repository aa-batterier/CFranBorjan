#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

double calculate_vector(struct list *vector)
{
	double sum = 0;
	for (int i = 0; i < size(vector); i++)
	{
		double *p = get(vector,i);
		sum += pow(*p,2);
	}
	return sqrt(sum);
}

int main(void)
{
	struct list *vector = new_list();
	double values[] = {5,3,1};
	for (int i = 0; i < 3; i++)
	{
		double *p = (double*)malloc(sizeof(double));
		*p = values[i];
		add_last(vector,p);
	}
	printf("Summan av vektorn (5,3,1) är %g.\n",calculate_vector(vector));
	exit(0);
}
