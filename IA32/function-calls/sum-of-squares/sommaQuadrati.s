#int sommaQuadrati(char* v, int n) {
#    int somma = 0; // somma <-> ebx, v <-> esi, n <-> edi
#    while (n>0) {  // if (n<=0) goto E
#        n--;
#        somma += sqr(v[n]);
#    }
#    return somma;
#}

.globl sommaQuadrati
sommaQuadrati:
    pushl %ebx      # prologo
    pushl %edi
    pushl %esi
    subl $4, %esp

    movl 20(%esp), %esi # v -> esi
    movl 24(%esp), %edi # n -> edi
    movl $0, %ebx       # somma = ebx <- 0

L:  cmpl $0, %edi
    jle E
    decl %edi
    movb (%esi,%edi), %al # al <- v[n]
    movsbl %al, %eax
    movl %eax, (%esp)
    call sqr
    addl %eax, %ebx
    jmp L
E:  movl %ebx, %eax

    addl $4, %esp   # epilogo
    popl %esi
    popl %edi
    popl %ebx
    ret
