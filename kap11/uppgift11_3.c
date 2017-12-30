#include <stdio.h>

int ortogonal(int *v1,int *v2,int n)
{
	int sum = 0;
	for (int *p = v1; p < v1+n; p++,v2++)
		sum += *p**v2;
	if (sum)
		return 0;
	return 1;
}

int main(void)
{
	int v1[] = {3,4,2},v2[] = {2,5,9};
	if (ortogonal(v1,v2,3))
		printf("Vektorerna (3,4,2) och (2,5,9) är ortogonala.\n");
	else
		printf("Vektorerna (3,4,2) och (2,5,9) är inte ortogonala.\n");
	return 0;
}
