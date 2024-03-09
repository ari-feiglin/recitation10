	.file	"fin-to-inf.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB30:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	.LC0(%rip), %rbp    // rbp = "%d\n"
	xorl	%ebx, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L2:
	movl	%ebx, %edx          // edx = j
	movq	%rbp, %rsi          // rsi = "%d\n"
	movl	$1, %edi            // edi = 1
	xorl	%eax, %eax          // 
	addl	$536870913, %ebx    // j += 0x20000001
	call	__printf_chk@PLT    // printf("%d\n", edx (prev value of j))
                                // really printf_chk but unimportant
	jmp	.L2                     // goto L2
	.cfi_endproc
.LFE30:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
