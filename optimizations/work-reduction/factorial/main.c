#include <stdio.h>
#define NUM     50
#define ITER    50000000

int factorial(int n);

int main() {
    int i, result;

    for (i = 0; i < ITER; i++)
        result = factorial(NUM);

    printf("%d\n", result);

    return 0;
}
