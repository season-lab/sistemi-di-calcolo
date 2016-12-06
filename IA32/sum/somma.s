#unsigned somma(unsigned n){
#    unsigned a = 0;  a <-> eax, n <-> ecx
#L:  if (n<=0) goto E;
#    a = a+n;
#    n--;
#    goto L;
#E:  return a;
#}

.globl somma

somma:
    movl 4(%esp), %ecx # ecx = n
    movl $0, %eax
L:  cmpl $0, %ecx
    jbe E
    addl %ecx, %eax
    decl %ecx
    jmp L
E:  ret
