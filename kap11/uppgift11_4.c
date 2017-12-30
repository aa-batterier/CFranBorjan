#include <stdio.h>
#include <string.h>

/* s2 till s1. */
int my_cpy(char *s1,char *s2,int n)
{
	if (strlen(s2) > n)
		return 0;
	while ((*s1++ = *s2++));
	return 1;
}

int main(void)
{
	char s1[50],s2[] = "Hej! Hur har du det!",s3[10];
	if (my_cpy(s1,s2,50))
		printf("%s\n",s1);
	else
		printf("Kan inte kopiera strängen, för stor.\n");
	if (my_cpy(s3,s2,10))
		printf("%s\n",s3);
	else
		printf("Kan inte kopiera strängen, för stor.\n");
	return 0;
}
