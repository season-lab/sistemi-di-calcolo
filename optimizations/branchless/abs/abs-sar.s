# questa implementazione non controlla alcun condition code
# ma sfrutta le proprietà dei complementi a 1 ed a 2
.globl abs

abs:
	movl 4(%esp), %eax
	movl %eax, %edx
	sarl $32, %edx
	xorl %edx, %eax
	subl %edx, %eax
	ret
