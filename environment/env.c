#include <stdio.h>

extern char** environ;

int main() {
    char** p = environ;
    while (*p) printf("%s\n", *p++);
    return 0;
}
