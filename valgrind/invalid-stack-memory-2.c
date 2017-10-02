#include <stdio.h>

int * init() {
	int buf[10] = { 0 };
	return buf;
}

int main() {
	int * b = init();
	printf("%d %d %d %d\n", b[0], b[1], b[2], b[3]);
	return 0;
}
