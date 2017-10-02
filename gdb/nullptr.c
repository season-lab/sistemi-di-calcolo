#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

char *p;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Syntax: %s <string>\n", argv[0]);
        return 1;
    }
    
    sprintf(p, "Input: %s", argv[1]);
    printf("%s\n", p);

    return 0;
}
