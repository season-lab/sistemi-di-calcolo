#include <stdio.h>

int * init() {
	int buf[10] = { 0 };
	return buf;
}

int main() {
	int * b = init();
	printf("%d\n", *b);
	return 0;
}
