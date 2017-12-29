#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Running on %s\n",getenv("HOSTNAME"));
	exit(0);
}
