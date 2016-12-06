# invocazione syscall write in eax: che numero? ==> 4
# unsigned mywrite(int fd,             -> ebx
#  eax             const void* buffer, -> ecx
#                  unsigned size);     -> edx

.globl mywrite

mywrite:
    pushl %ebx
    movl $4, %eax
    movl 8(%esp), %ebx
    movl 12(%esp), %ecx
    movl 16(%esp), %edx
    int $0x80
    popl %ebx
    ret
