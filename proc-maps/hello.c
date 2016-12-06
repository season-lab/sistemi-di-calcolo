#include <stdlib.h>
#include <stdio.h>
int x;

int main() {
    int* p = malloc(100);
    char* q = "hello";
    printf("&x=%p\n", &x); // DATA
    printf("&p=%p\n", &p); // STACK
    printf("&q=%p\n", &q); // STACK
    printf("q=%p\n", q);
    printf("p=%p\n", p);
    scanf("%d", &x);
    return 0;
}
