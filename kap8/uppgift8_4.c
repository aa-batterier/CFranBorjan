#include <stdio.h>

_Bool min_memcmp(double f1[],double f2[],int b)
{
	for (int i = 0; i < b; i++)
		if (f1[i] != f2[i])
			return 0;
	return 1;
}

void test_f(double f1[],double f2[],int b)
{
	if (min_memcmp(f1,f2,b) == 1)
		printf("Fälten är lika.\n");
	else
		printf("Fälten är olika.\n");
}

int main(void)
{
	double f1[] = {1.0,2.1,2.2,3.2},f2[] = {1.0,2.1,2.2,3.2};
	printf("Första testet, båda fälter är lika:\n");
	test_f(f1,f2,4);
	printf("Andra testet, jag har ändrat på fält nr 1, men testar bara de två första byten:\n");
	f1[2] = 5.6;
	f1[3] = 4.7;
	test_f(f1,f2,2);
	printf("Tredje testet, samma värden som i andra testet, dock testar jag här alla fyra byten:\n");
	test_f(f1,f2,4);
	return 0;
}
