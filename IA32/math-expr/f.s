.globl f

f: movl $10, %ecx # ciao
   movl $20, %eax
   imull $3, %eax
   imull $3, %eax
   addl %ecx, %eax
   ret

