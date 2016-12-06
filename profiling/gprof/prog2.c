#include <string.h>
#include <stdlib.h>

#define M 1000000000
#define N 10000

void init(int *v, int n) {
	memset(v, n*sizeof(int), 255);
}

void A(int *v, int n) {
	int i = 0;
	for (i=0; i<n; i++) v[i] = v[i] + v[i];
}

void B(int *v, int n) {
	int i = 0;
	for (i=0; i<n; i++) v[i] = v[i] >> 1;
}

int main() {
	int* v = malloc(N*sizeof(int)), i;
	init(v, N);
	for (i=0; i<M/N; i++) {
		A(v, N);
		B(v, N);
	}
	free(v);
	return 0;
}
