#include <stdio.h>

int somma(int x, int y) {
	return x + y;
}

int main() {
	int res = somma(10, 20);
	printf("%d\n", res);
	return 0;
}
