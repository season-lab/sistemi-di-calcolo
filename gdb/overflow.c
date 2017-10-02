#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int i = 0;
    int sum = 0;

    while (i < 500) {
        sum = sum + i*i*i;
        i += 2;
    }

    printf("%d\n", sum);
    return 0;
}
