#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ITEMS   512

double A[ITEMS][ITEMS];
double B[ITEMS][ITEMS];
double C[ITEMS][ITEMS];

int main() {
    int i, j, k;
    struct timespec start, stop;

    printf("Initializing matrices...\n");

    // initialize A
    for (i = 0; i < ITEMS; i++) {
        for (j = 0; j < ITEMS; j++) {
            A[i][j] = i*j;
        }
    }

    // copy A into B
    memcpy(B, A, sizeof(A)); // sizeof(A) == ITEMS*ITEMS*sizeof(double)

    printf("Multiplying matrices...\n");
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    #if VERSION == 0    // ijk scheme
    for (i=0; i<ITEMS; i++) {
        for (j=0; j<ITEMS; j++) {
            double sum = 0.0;
            for (k=0; k<ITEMS; k++) {
                sum += A[i][k]*B[k][j];
            }
            C[i][j] = sum;
        }
    }
    #elif VERSION == 1  // kij scheme
    for (k=0; k<ITEMS; k++) {
        for (i=0; i<ITEMS; i++) {
            double r = A[i][k];
            for (j=0; j<ITEMS; j++) {
                C[i][j] += r * B[k][j];
            }
        }
    }
    #elif VERSION == 2 // jki scheme
    for (j=0; j<ITEMS; j++) {
        for (k=0; k<ITEMS; k++) {
            double r = B[k][j];
            for (i=0; i<ITEMS; i++) {
                C[i][j] += A[i][k] * r;
            }
        }
    }
    #endif

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

    double ms = (stop.tv_sec - start.tv_sec) * 1E3 +
                (stop.tv_nsec - start.tv_nsec) / 1E6;

    printf("Elapsed milliseconds: %f\n", ms);

    return 0;
}
