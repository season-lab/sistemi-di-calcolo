/*
static int factorial_aux(int n, int acc) {
    while (n>=2)
        acc *= n--;
    return acc;
}

int factorial(int n) {
    return factorial_aux(n, 1);
}
*/

int factorial(int n) {
    int acc = 1;
    while (n>=2)
        acc *= n--;
    return acc;
}
