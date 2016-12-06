.globl my_write

my_write:
    pushl %ebx
    movl $4, %eax
    movl 8(%esp), %ebx
    movl 12(%esp), %ecx
    movl 16(%esp), %edx
    int $0x80
    popl %ebx
    ret
