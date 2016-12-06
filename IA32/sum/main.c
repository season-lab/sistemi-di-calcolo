#include <stdio.h>

unsigned somma(unsigned n);

int main() {
    unsigned x = somma(5); // x = 1+2+3+4+5
    printf("x=%u\n", x);
    return 0;
}
