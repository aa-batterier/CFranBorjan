#include <stdio.h>

int main(void)
{
	for (float x = -1.0; x <= 1.0; x += 0.1)
		printf("%d\n",2*x*x-5*x+1);
}
