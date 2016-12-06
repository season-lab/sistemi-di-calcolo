int f() {
    int x, y; // y->A, x->C
    x = 10;   // movl $10, %ecx
    y = 20;   // movl $20, %eax
    //y = x+y*3;

    y = 3 * y; // imull $3, %eax
    y = y + x; // addl %ecx, %eax

    return y;  // ret
}
