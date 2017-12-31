#include <stdio.h>
#include <string.h>

char *my_search(char *s1,char *s2)
{
	while (*s1)
	{
		for (char *p = s2; p < s2+strlen(s2); p++)
			if (*p == *s1)
				return p;
		s1++;
	}
	return NULL;
}


int main(void)
{
	char s1[] = "Andreas Johansson",s2[] = "Hej! Hur har du det?",s3[] = "www",*p;
	if ((p = my_search(s1,s2)) == NULL)
		printf("Inga lika tecken.\n");
	else
		printf("Första lika teckenet är %c.\n",*p);
	if ((p = my_search(s1,s3)) == NULL)
		printf("Inga lika tecken.\n");
	else
		printf("Första lika teckenet är %c.\n",*p);
	return 0;
}
