	.file	"fin-to-inf.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$121, -64(%rbp) // buf[0] = 'y'
	movq	$0, -56(%rbp)   // set the rest of buf to 0
	movq	$0, -48(%rbp)   //   
	movq	$0, -40(%rbp)   //
	movq	$0, -32(%rbp)   //
	movq	$0, -24(%rbp)   //
	movw	$0, -16(%rbp)   //
	movl	$0, -68(%rbp)   // j = 0
	jmp	.L2
.L5:
	movl	-68(%rbp), %edx // edx = j
	movl	%edx, %eax      // eax = j * 0x20000001
	sall	$29, %eax       // 
	addl	%edx, %eax      //
	movl	%eax, %esi      // esi = j * 0x20000001
	leaq	.LC0(%rip), %rdi    // rdi = "%d\n"
	movl	$0, %eax
	call	printf@PLT          // printf("%d\n", j * 0x20000001);
	movzbl	-64(%rbp), %eax     // eax = buf[0]
	cmpb	$120, %al           // if buf[0] == 'x'
	je	.L8                     // then goto L8
	addl	$1, -68(%rbp)       // j++
.L2:
	cmpl	$8, -68(%rbp)   // if buf[0] <= 8
	jle	.L5                 // then jump to L5
	jmp	.L4                 // else jump to L4
.L8:
	nop
.L4:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
