#include <stdio.h>
int main()
{
	char* arg = "Hello";
	char* a[] = {arg, " World"};
	printf("%s %s\n", a[0], a[1]);
	return 0;
}