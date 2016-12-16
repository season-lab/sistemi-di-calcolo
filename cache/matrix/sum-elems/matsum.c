#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 10000

int sum(int** m, int n) { // matrice nxn
    int i, j, s = 0;
    #ifdef BYCOL
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            s = s + m[i][j];
    #else
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            s = s + m[i][j];
    #endif
    return s;
}

int main() {
    int** m = malloc(sizeof(int*)*N);
    assert(m!=NULL);
    int i, s=0;
    for (i=0; i<N; i++) {
        m[i] = calloc(sizeof(int),N);
        assert(m[i] != NULL);
    }
    for (i=0; i<100; i++)
        s += sum(m,N);
    printf("Risultato = %d\n", s);
    return 0;
}
