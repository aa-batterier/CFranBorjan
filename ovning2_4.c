#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("Minsta talet som kan lagras i typen int är %d.\nStörsta talet som kan lagras i typen int är %d.\nDecimal noggranhet för float är %d.\nDecimal noggranhet för double är %d.\n",INT_MIN,INT_MAX,FLT_DIG,DBL_DIG);
	return 0;
}
