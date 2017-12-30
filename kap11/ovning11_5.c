#include <stdio.h>
#include <string.h>

void my_strcat(char *s1,const char *s2)
{
	/*while (*s1)
		s1++;*/
	while (*s1++);
	s1 -= 1;
	while ((*s1++ = *s2++));
}

int main(void)
{
	char s1[50] = "Hej! \0",s2[30] = "Vad gör du!\0";
	my_strcat(s1,s2);
	printf("%s\n",s1);
	return 0;
}
