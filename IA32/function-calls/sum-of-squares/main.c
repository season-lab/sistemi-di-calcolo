#include <stdio.h>

int sommaQuadrati(char*,int);

int main() {
    char v[] = { 2, 3, 4 };
    printf("%d\n", sommaQuadrati(v,3));
    // 2*2+3*3+4*4=4+9+16=29
    return 0;
}
