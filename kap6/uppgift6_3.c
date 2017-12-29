#include <stdio.h>

_Bool primtal(int prim)
{
	for (int i = 2; i < prim; i++)
		if (prim % i == 0)
			return 0;
	return 1;
}
