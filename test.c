#include <stdio.h>

int main(void)
{
	int a[] = {2, 4, 6};
	int *b;

	b = a + 1;
	printf("%ld\n", sizeof(a) / sizeof(a[0]));
	printf("%ld\n", sizeof(b));
	printf("%ld\n", sizeof(*b) / sizeof(b[0]));
	return 0;
}
