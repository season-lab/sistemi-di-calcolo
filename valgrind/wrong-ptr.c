#include <stdio.h>

int p,q,r,s,t;

void foo(int * a) {
	a[1] = 10;
}

int main() {
	foo(&r);
	printf("%d %d %d %d %d\n", p, q, r, s, t);
	return 0;
}
