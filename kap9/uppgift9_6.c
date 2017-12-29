#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 10

void cpy(char *s1,const char *s2,int n)
{
	int i;
	if ((i = (strlen(s2) - 1) - n) < 0)
	{
		for (int j = 0; j < (-i); j++)
			s1[j] = '_';
		int k = 0;
		for (int j = (-i); j < n || s2[k] != '\0'; j++)
		{
			s1[j] = s2[k];
			k++;
		}
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			s1[j] = s2[i];
			i++;
		}
	}
	s1[N+1] = '\0';
}

int main(void)
{
	char s1[N+1],s2[] = "Hej\0";
	cpy(s1,s2,N);
	printf("%s\n",s1);
	return 0;
}
