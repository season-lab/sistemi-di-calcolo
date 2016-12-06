#include <stdio.h>
#include <time.h>

int main() {

    struct timespec start, stop;

    clock_gettime(CLOCK_REALTIME, &start);

    /// do something
    long i, x = 0;
    for (i=0; i<1; i++) x += (i*x+i) / i;

    clock_gettime(CLOCK_REALTIME, &stop);

    double result = (stop.tv_sec - start.tv_sec) * 1e9 +
                    (stop.tv_nsec - start.tv_nsec);    // in nanoseconds

    printf("%f\n", result);

    return 0;
}
