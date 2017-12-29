#include <stdio.h>

int main(void)
{
	printf("char = %lu\nshort int = %lu\nint = %lu\nlong int = %lu\nlong long int = %lu\nfloat = %lu\ndouble = %lu\nlong double = %lu\n",sizeof(char),sizeof(short int),sizeof(int),sizeof(long int),sizeof(long long int),sizeof(float),sizeof(double),sizeof(long double));
	return 0;
}
