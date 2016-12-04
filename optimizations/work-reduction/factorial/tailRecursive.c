static int factorial_aux(int n, int acc) {
    if (n<2) return acc;
    return factorial_aux(n-1, n*acc);
}

int factorial(int n) {
    return factorial_aux(n, 1);
}
