#include <stdlib.h>
#include <stdio.h>

#define LEN 10

int * foo() {
	int * buf = malloc(sizeof(int) * LEN);
	// interesting stuff
	free(buf);
	// other stuff
	return buf;
}

int main() {
	int * b = foo();
	printf("%d\n", *b);
	return 0;
}
