# void swap(char* x, char* y) {
#    char a = *x;  a <-> al
#    char c = *y;  c <-> cl
#    *x = c;
#    *y = a;
# }

.globl swap

swap:
    movl 4(%esp), %eax  # eax <-> x
    movb (%eax), %al

    movl 8(%esp), %ecx  # ecx <-> y
    movb (%ecx), %cl

    movl 4(%esp), %edx  # edx <-> x
    movb %cl, (%edx)

    movl 8(%esp), %edx  # edx <-> y
    movb %al, (%edx)
    ret
