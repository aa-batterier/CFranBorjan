#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr,"användande: %s <temperatur i Farenheit>\n",argv[0]);
		exit(1);
	}
	printf("Temperaturen %s grader i Farenheit är %g grader i Celsius.\n",argv[1],(atof(argv[1])-32)*5/9);
	exit(0);
}
