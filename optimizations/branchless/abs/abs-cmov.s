# CMOV sposterà l'argomento negato -x nel registro eax soltanto se -x
# non ha il bit del segno settato, quindi quando per x lo è (ossia x<0)
.globl abs

abs:
	movl 4(%esp), %eax
	movl %eax, %edx
	negl %edx
	cmovns %edx, %eax
	ret
