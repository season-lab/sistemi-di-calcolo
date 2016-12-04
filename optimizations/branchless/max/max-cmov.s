# int max(int a, int b);
#
# questa implementazione sposta a in %eax quando a>=b
.globl max

max:
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	ret
