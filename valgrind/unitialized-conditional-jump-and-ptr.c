#include <stdio.h>

void foo(int *a) {
	if (a == NULL)
		return;
	printf("a is %d\n", *a);
}

int main() {
	int *a;
	foo(a);
	return 0;
}
