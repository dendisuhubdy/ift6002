#include <stdio.h>

int hash(char *v, int M)
{
	int h = 0;
	int a = 127;
	for (; *v != '\0'; v++)
		h = (a*h + *v) % M;
	return h;
}

int main()
{
	char *test = "test";
	hash(test, 11);
	return 0;
}
