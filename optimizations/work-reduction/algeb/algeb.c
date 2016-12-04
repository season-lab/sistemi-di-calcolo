#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N   1000
#define REP 250000000

typedef struct {
    double x, y, r;
} disc;

int collide(disc* d1, disc* d2) {
    double h = d1->x - d2->x;
    double v = d1->y - d2->y;
    double d = d1->r + d2->r;
#ifdef OPT
    return d*d <= h*h + v*v;
#else
    return d <= sqrt(h*h + v*v);
#endif
}

int main() {
    disc d1 = { 1.0, 1.0, 1.0 };
    disc d2 = { 500.0, 500.0, 1.0 };
    int i, res = 0;

    for (i=0; i<REP; ++i) {
        d2.r++;
        res += collide(&d1, &d2);
    }

    printf("res=%d\n", res);
    return 0;
}
