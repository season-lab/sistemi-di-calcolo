#include <unistd.h>
#include <stdio.h>

int main() {

    ssize_t scritti;
    char testo[] = "pen pineapple\n";

    scritti = write(1, testo, sizeof(testo));

    printf("%lu\n", scritti);
    return 0;
}
