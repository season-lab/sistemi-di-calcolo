# int f(int x) {
#    return x+g();
# }

.globl f

f:  pushl %ebx # prologo
    movl 8(%esp), %ebx
    call g   # ebx non cambia durante g()
    addl %ebx, %eax # eax ritorno di g
    popl %ebx  # epilogo
    ret
