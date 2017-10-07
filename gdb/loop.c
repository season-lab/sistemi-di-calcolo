#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i = 0;
    int sum = 0;

    while (i < 20)
        sum += i; i++;

    printf("%d\n", sum);

    return 0;
}
