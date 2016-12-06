/*
unsigned somma(unsigned n){
    unsigned a = 0;
    while (n>0){
        a = a+n;
        n--;
    }
    return a;
}
*/
unsigned somma(unsigned n){
    unsigned a = 0;
L:  if (n<=0) goto E;
    a = a+n;
    n--;
    goto L;
E:
    return a;
}

