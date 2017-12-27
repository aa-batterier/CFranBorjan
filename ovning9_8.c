#include <stdio.h>
#include <string.h>

int last_index_of(const char *s,char c)
{
	char *p;
	if ((p = strrchr(s,c)) == NULL)
		return -1;
	else
		return p-s;
}

void test_f(const char *s,char c)
{
	printf("Ser om tecknet %c finns med i strängen %s\n",c,s);
	if (last_index_of(s,c) < 0)
		printf("Tecknet %c finns inte med i strängen %s\n",c,s);
	else
		printf("Tecknet %c finns med i strängen %s\n",c,s);
}

int main(void)
{
	char s[] = "Hur har du det\0",c1 = 'a',c2 = 'o';
	test_f(s,c1);
	test_f(s,c2);
	return 0;
}
