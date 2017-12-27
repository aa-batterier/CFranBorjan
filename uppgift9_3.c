#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char s[100],v[] = "aouåeiyäö";
	printf("Skriv text på p-språket: ");
	fgets(s,100,stdin);
	for (int i = 0; s[i] != '\0'; i++)
	{
		putchar(s[i]);
		if (strchr(v,tolower(s[i])) != NULL)
			i += 2;
	}
	return 0;
}
