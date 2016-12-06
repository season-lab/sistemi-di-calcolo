#include <stdlib.h>
#include <stdio.h>

int sum(int* v, int n) {
    int i, j, s = 0;
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            s += v[i]+j;
    return s;
}

#define N 50000

int main() {
    int* p = malloc(sizeof(int)*N);
    int s = sum(p, N);
    free(p);
    printf("%d\n", s);
    return 0;
}
