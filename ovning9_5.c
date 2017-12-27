#include <stdio.h>

int main(void)
{
	char v[11];
	char a[] = "  /  /  ";
	printf("Ange datum som åååå-mm-dd: ");
	scanf("%s",v);
	a[0] = v[5];
	a[1] = v[6];
	a[3] = v[8];
	a[4] = v[9];
	a[6] = v[2];
	a[7] = v[3];
	printf("Amerikanskt datum: %s\n",a);
}
