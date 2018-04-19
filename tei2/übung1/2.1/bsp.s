	.file	"bsp.c"
	.section	.rodata
.LC0:
	.string	"x=%d y=%d z=%d\n"
	.text
	.globl	globalfunction
	.type	globalfunction, @function
globalfunction:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-4(%rbp), %ecx
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	subl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	globalfunction, .-globalfunction
	.section	.rodata
.LC1:
	.string	"sth=%u\n"
	.text
	.globl	globalfunction2
	.type	globalfunction2, @function
globalfunction2:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	globalfunction2, .-globalfunction2
	.section	.rodata
.LC2:
	.string	"Hallo %s!\n"
	.align 8
.LC3:
	.string	"Die ganze Zahl %d mit Vorzeichen %+d und als hex %x und %X.\n"
	.align 8
.LC4:
	.string	"Die Variable k: %d und nochmal k: %u.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$111111, -4(%rbp)
	movl	$-222222, -8(%rbp)
	movl	$-961633963, -12(%rbp)
	movw	$67, -14(%rbp)
	leaq	-14(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %esi
	movl	-4(%rbp), %ecx
	movl	-4(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-8(%rbp), %esi
	movl	-8(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	globalfunction2
	movl	$2, %esi
	movl	$1, %edi
	call	globalfunction
	movl	$2, %esi
	movl	$1, %edi
	call	globalfunction
	movl	$0, %eax
	call	globalfunction2
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
