#include <stdlib.h>
#include <stdio.h>

// no tail recursion
int sum(int n) {
    if (n<1) return 0;
    return sum(n-1)+n;
}

// tail recursion
int sum_opt_rec(int n, int sum) {
    if (n<1) return sum;
    return sum_opt_rec(n-1, sum+n);
}

int sum_opt(int n) {
    return sum_opt_rec(n, 0);
}

// manual tail recursion
int sum_opt_iter(int n, int sum) {
loop:
    if (n<1) return sum;
    sum = sum+n;
    n = n-1;
    goto loop;
}

int sum_opt_man(int n) {
    return sum_opt_iter(n, 0);
}

int main() {
    int i, s=0;
	for (i=0; i<M; i++) s += F(100+i%N);
    printf("res=%d\n", s);
	return 0;
}
