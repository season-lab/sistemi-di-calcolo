#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* touppercase(const char* s) {
    char* cap = strdup(s);
    int len = strlen(cap);
    int k;
    for (k = 0; k < len; ++k) {
        // ASCII: 'a' == 97, 'z' == 122, 'A' = 65, 'Z' = 90
        if (cap[k] >= 97 && cap[k] <= 122) cap[k]-= 32;
    }
    return cap;
}


int main(int argc, char* argv[]) {
    char* s = touppercase(argv[0]);

    while (*s != 0) {
        printf("%c\n", *s);
        s++;
    }

    free(s);
    return 0;
}
