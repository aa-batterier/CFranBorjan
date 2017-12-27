#include <stdio.h>
#include <string.h>

int main(void)
{
	char v[11];
	char a[] = "  /  /  ";
	printf("Ange datum som åååå-mm-dd: ");
	scanf("%s",v);
	strncpy(a,v+5,2);
	strncpy(a+3,v+8,2);
	strncpy(a+6,v+2,2);
	printf("Amerikanskt datum: %s\n",a);
	return 0;
}
