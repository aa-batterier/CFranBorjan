#include <stdio.h>

int main(void)
{
	float x = 5.8,*q1 = &x,*q2;
	printf("q1 = %f\nq2 = %f\n",*q1,*q2);
	q2 = NULL;
	printf("q2 = %f\n",*q2);
	return 0;
}
