#include<stdio.h>

void swap(char* x, char* y);

int main() {
    char a = 'A', b = 'B';
    swap(&a, &b);
    printf("a=%c, b=%c\n", a, b);
    return 0;
}
