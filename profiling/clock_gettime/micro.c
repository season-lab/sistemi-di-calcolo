#include <stdio.h>
#include <time.h>

int main() {
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_REALTIME, &stop);
    double res = (stop.tv_sec-start.tv_sec) * 1e6 +
		 (stop.tv_nsec-start.tv_nsec) * 1e-3; // in microseconds
    printf("%f\n", res);
    return 0;
}
