#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr,"användande: %s <bensinförbrukning i miles/gallon>\n",argv[0]);
		exit(1);
	}
	printf("%g liter/milen\n",3.785/atof(argv[1])/1.609*10);
	exit(0);
}
