int sqr(int);

int sommaQuadrati(char* v, int n) {
    int somma = 0;
    while (n>0) {
        n--;
        somma += sqr(v[n]);
    }
    return somma;
}
