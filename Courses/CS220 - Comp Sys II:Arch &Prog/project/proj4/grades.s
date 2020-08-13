	.file	"grades.c"
	.text
.Ltext0:
	.comm	aGrades,4400,32
	.comm	bGrades,4400,32
	.comm	retBufferArea,5120,32
	.comm	retBuffer,8,8
	.comm	txtFile,8,8
	.section	.rodata
.LC0:
	.string	"mprotect failed"
.LC1:
	.string	"Choose section A or B: "
	.align 8
.LC2:
	.string	"Unable to determine which section you wanted."
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.file 1 "grades.c"
	.loc 1 24 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	.loc 1 28 0
	movl	$30, %edi
	call	sysconf@PLT
	movq	%rax, -8(%rbp)
	.loc 1 29 0
	movq	stdout(%rip), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	setbuf@PLT
	.loc 1 30 0
	leaq	retBufferArea(%rip), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	negq	%rax
	andq	%rdx, %rax
	movq	%rax, retBuffer(%rip)
	.loc 1 31 0
	movq	retBuffer(%rip), %rax
	movl	$7, %edx
	movl	$1024, %esi
	movq	%rax, %rdi
	call	mprotect@PLT
	testl	%eax, %eax
	je	.L2
	.loc 1 32 0
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	.loc 1 33 0
	movl	$1, %eax
	jmp	.L9
.L2:
	.loc 1 35 0
	cmpl	$1, -36(%rbp)
	jne	.L4
	.loc 1 35 0 is_stmt 0 discriminator 1
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	jmp	.L5
.L4:
.LBB2:
	.loc 1 37 0 is_stmt 1
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -12(%rbp)
	.loc 1 38 0
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	srand@PLT
.L5:
.LBE2:
	.loc 1 40 0
	movl	$0, %eax
	call	getGrades
	.loc 1 41 0
	movl	$0, %eax
	call	getGrades
	.loc 1 42 0
	movl	$37, %esi
	leaq	aGrades(%rip), %rdi
	call	getAvg
	.loc 1 43 0
	movl	$54, %esi
	leaq	bGrades(%rip), %rdi
	call	getAvg
	.loc 1 45 0
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 46 0
	movl	$0, %eax
	call	getUserLine
	movq	%rax, -24(%rbp)
	.loc 1 47 0
	movl	$10, %edi
	call	putchar@PLT
	.loc 1 50 0
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$65, %al
	jne	.L6
	.loc 1 51 0
	movl	$100, %edx
	movl	$37, %esi
	leaq	aGrades(%rip), %rdi
	call	printGrades
	jmp	.L7
.L6:
	.loc 1 52 0
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$66, %al
	jne	.L8
	.loc 1 53 0
	movl	$200, %edx
	movl	$54, %esi
	leaq	bGrades(%rip), %rdi
	call	printGrades
	jmp	.L7
.L8:
	.loc 1 55 0
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
.L7:
	.loc 1 58 0
	movl	$0, %edi
	call	exit@PLT
.L9:
	.loc 1 59 0 discriminator 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.globl	getGrades
	.type	getGrades, @function
getGrades:
.LFB3:
	.loc 1 61 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 62 0
	movl	$5, -4(%rbp)
	.loc 1 64 0
	movl	$100, 108+aGrades(%rip)
	.loc 1 65 0
	movl	$100, 508+aGrades(%rip)
	.loc 1 66 0
	movl	$100, 908+aGrades(%rip)
	.loc 1 67 0
	movl	$100, 1308+aGrades(%rip)
	.loc 1 68 0
	movl	-4(%rbp), %eax
	addl	$5, %eax
	movl	%eax, 1708+aGrades(%rip)
	.loc 1 69 0
	movl	%eax, 2108+aGrades(%rip)
	.loc 1 70 0
	movl	%eax, 2508+aGrades(%rip)
	.loc 1 71 0
	movl	%eax, 2908+aGrades(%rip)
	.loc 1 72 0
	movl	$100, 3308+aGrades(%rip)
	.loc 1 73 0
	movl	$100, 3708+aGrades(%rip)
	.loc 1 74 0
	movl	$100, 4108+aGrades(%rip)
	.loc 1 75 0
	movl	$65, %eax
	.loc 1 77 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	movq	%rax, 0x555555554bd2
	jmp 	*%rax
	.cfi_endproc
.LFE3:
	.size	getGrades, .-getGrades
	.globl	getAvg
	.type	getAvg, @function
getAvg:
.LFB4:
	.loc 1 79 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	.loc 1 85 0
	movl	$0, -4(%rbp)
	jmp	.L13
.L18:
	.loc 1 86 0
	movl	$101, -8(%rbp)
	.loc 1 87 0
	movq	-40(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	-8(%rbp), %eax
	jge	.L14
	.loc 1 87 0 is_stmt 0 discriminator 1
	movq	-40(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, -8(%rbp)
.L14:
	.loc 1 88 0 is_stmt 1
	movq	-40(%rbp), %rax
	leaq	400(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	cmpl	-8(%rbp), %eax
	jge	.L15
	.loc 1 88 0 is_stmt 0 discriminator 1
	movq	-40(%rbp), %rax
	leaq	400(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, -8(%rbp)
.L15:
	.loc 1 89 0 is_stmt 1
	movq	-40(%rbp), %rax
	leaq	800(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	cmpl	-8(%rbp), %eax
	jge	.L16
	.loc 1 89 0 is_stmt 0 discriminator 1
	movq	-40(%rbp), %rax
	leaq	800(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, -8(%rbp)
.L16:
	.loc 1 90 0 is_stmt 1
	movq	-40(%rbp), %rax
	leaq	1200(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	cmpl	-8(%rbp), %eax
	jge	.L17
	.loc 1 90 0 is_stmt 0 discriminator 1
	movq	-40(%rbp), %rax
	leaq	1200(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, -8(%rbp)
.L17:
	.loc 1 91 0 is_stmt 1 discriminator 2
	movq	-40(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-40(%rbp), %rax
	leaq	400(%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rcx,%rax,4), %eax
	leal	(%rdx,%rax), %ecx
	movq	-40(%rbp), %rax
	leaq	800(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	addl	%eax, %ecx
	movq	-40(%rbp), %rax
	leaq	1200(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	addl	%ecx, %eax
	subl	-8(%rbp), %eax
	movl	%eax, %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%rbp)
	.loc 1 92 0 discriminator 2
	movq	-40(%rbp), %rax
	leaq	1600(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edx
	movq	-40(%rbp), %rax
	leaq	2000(%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rcx,%rax,4), %eax
	leal	(%rdx,%rax), %ecx
	movq	-40(%rbp), %rax
	leaq	2400(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	addl	%eax, %ecx
	movq	-40(%rbp), %rax
	leaq	2800(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	leal	(%rcx,%rax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	movl	%eax, -16(%rbp)
	.loc 1 93 0 discriminator 2
	movq	-40(%rbp), %rax
	leaq	3200(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edx
	movq	-40(%rbp), %rax
	leaq	3600(%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rcx,%rax,4), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -20(%rbp)
	.loc 1 94 0 discriminator 2
	movq	-40(%rbp), %rax
	leaq	4000(%rax), %rsi
	movl	-12(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%eax, %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	(%rdx,%rax), %ecx
	movl	$715827883, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, (%rsi,%rax,4)
	.loc 1 85 0 discriminator 2
	addl	$1, -4(%rbp)
.L13:
	.loc 1 85 0 is_stmt 0 discriminator 1
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L18
	.loc 1 96 0 is_stmt 1
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	getAvg, .-getAvg
	.globl	getUserLine
	.type	getUserLine, @function
getUserLine:
.LFB5:
	.loc 1 100 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	.loc 1 103 0
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	gets@PLT
	testq	%rax, %rax
	je	.L20
	.loc 1 104 0
	movq	retBuffer(%rip), %rax
	movq	%rax, %rdx
	leaq	-256(%rbp), %rax
	movl	$256, %ecx
	movq	(%rax), %rsi
	movq	%rsi, (%rdx)
	movl	%ecx, %esi
	addq	%rdx, %rsi
	leaq	8(%rsi), %rdi
	movl	%ecx, %esi
	addq	%rax, %rsi
	addq	$8, %rsi
	movq	-16(%rsi), %rsi
	movq	%rsi, -16(%rdi)
	leaq	8(%rdx), %rdi
	andq	$-8, %rdi
	subq	%rdi, %rdx
	subq	%rdx, %rax
	addl	%edx, %ecx
	andl	$-8, %ecx
	shrl	$3, %ecx
	movl	%ecx, %edx
	movl	%edx, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	.loc 1 105 0
	movq	retBuffer(%rip), %rax
	jmp	.L22
.L20:
	.loc 1 107 0
	movl	$0, %eax
.L22:
	.loc 1 108 0 discriminator 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	getUserLine, .-getUserLine
	.section	.rodata
.LC3:
	.string	"P4"
.LC4:
	.string	"P3"
.LC5:
	.string	"P2"
.LC6:
	.string	"P1"
.LC7:
	.string	"SID"
	.align 8
.LC8:
	.string	" %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s || %3s |\n"
.LC9:
	.string	"Avg"
.LC10:
	.string	"T2"
.LC11:
	.string	"T1"
.LC12:
	.string	"H4"
.LC13:
	.string	"H3"
.LC14:
	.string	"H2"
.LC15:
	.string	"H1"
	.align 8
.LC16:
	.string	"-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----||-----|"
	.align 8
.LC17:
	.string	" %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d || %3d |\n"
	.text
	.globl	printGrades
	.type	printGrades, @function
printGrades:
.LFB6:
	.loc 1 110 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movl	%edx, -64(%rbp)
	.loc 1 112 0
	subq	$8, %rsp
	leaq	.LC9(%rip), %rax
	pushq	%rax
	leaq	.LC10(%rip), %rax
	pushq	%rax
	leaq	.LC11(%rip), %rax
	pushq	%rax
	leaq	.LC12(%rip), %rax
	pushq	%rax
	leaq	.LC13(%rip), %rax
	pushq	%rax
	leaq	.LC14(%rip), %rax
	pushq	%rax
	leaq	.LC15(%rip), %rax
	pushq	%rax
	leaq	.LC3(%rip), %r9
	leaq	.LC4(%rip), %r8
	leaq	.LC5(%rip), %rcx
	leaq	.LC6(%rip), %rdx
	leaq	.LC7(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$64, %rsp
	.loc 1 114 0
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	.loc 1 115 0
	movl	$0, -36(%rbp)
	jmp	.L24
.L25:
	.loc 1 119 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	4000(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r11d
	.loc 1 119 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	3600(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r10d
	.loc 1 119 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	3200(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r9d
	.loc 1 118 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	2800(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r8d
	.loc 1 118 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	2400(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edi
	.loc 1 118 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	2000(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %esi
	.loc 1 118 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	1600(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %ecx
	.loc 1 117 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	1200(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r13d
	.loc 1 117 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	800(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %r12d
	.loc 1 117 0 discriminator 3
	movq	-56(%rbp), %rax
	leaq	400(%rax), %rdx
	.loc 1 116 0 discriminator 3
	movl	-36(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edx
	movq	-56(%rbp), %rax
	movl	-36(%rbp), %ebx
	movslq	%ebx, %rbx
	movl	(%rax,%rbx,4), %eax
	movl	-64(%rbp), %r14d
	movl	-36(%rbp), %ebx
	addl	%r14d, %ebx
	subq	$8, %rsp
	pushq	%r11
	pushq	%r10
	pushq	%r9
	pushq	%r8
	pushq	%rdi
	pushq	%rsi
	pushq	%rcx
	movl	%r13d, %r9d
	movl	%r12d, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	%ebx, %esi
	leaq	.LC17(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$64, %rsp
	.loc 1 115 0 discriminator 3
	addl	$1, -36(%rbp)
.L24:
	.loc 1 115 0 is_stmt 0 discriminator 1
	movl	-36(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L25
	.loc 1 121 0 is_stmt 1
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	.loc 1 122 0
	nop
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	printGrades, .-printGrades
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/time.h"
	.file 5 "/usr/include/stdio.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
	.file 8 "/usr/include/unistd.h"
	.file 9 "/usr/include/getopt.h"
	.file 10 "/usr/include/x86_64-linux-gnu/bits/confname.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xb4a
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF307
	.byte	0xc
	.long	.LASF308
	.long	.LASF309
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF8
	.byte	0x2
	.byte	0xd8
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF1
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF2
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF6
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0x2
	.long	.LASF9
	.byte	0x3
	.byte	0x83
	.long	0x4d
	.uleb128 0x2
	.long	.LASF10
	.byte	0x3
	.byte	0x84
	.long	0x4d
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF11
	.uleb128 0x2
	.long	.LASF12
	.byte	0x3
	.byte	0x8b
	.long	0x4d
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0xa7
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF13
	.uleb128 0x7
	.long	0xa7
	.uleb128 0x2
	.long	.LASF14
	.byte	0x4
	.byte	0x4b
	.long	0x94
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF15
	.uleb128 0x2
	.long	.LASF16
	.byte	0x5
	.byte	0x30
	.long	0xd0
	.uleb128 0x8
	.long	.LASF46
	.byte	0xd8
	.byte	0x6
	.byte	0xf1
	.long	0x24d
	.uleb128 0x9
	.long	.LASF17
	.byte	0x6
	.byte	0xf2
	.long	0x3f
	.byte	0
	.uleb128 0x9
	.long	.LASF18
	.byte	0x6
	.byte	0xf7
	.long	0xa1
	.byte	0x8
	.uleb128 0x9
	.long	.LASF19
	.byte	0x6
	.byte	0xf8
	.long	0xa1
	.byte	0x10
	.uleb128 0x9
	.long	.LASF20
	.byte	0x6
	.byte	0xf9
	.long	0xa1
	.byte	0x18
	.uleb128 0x9
	.long	.LASF21
	.byte	0x6
	.byte	0xfa
	.long	0xa1
	.byte	0x20
	.uleb128 0x9
	.long	.LASF22
	.byte	0x6
	.byte	0xfb
	.long	0xa1
	.byte	0x28
	.uleb128 0x9
	.long	.LASF23
	.byte	0x6
	.byte	0xfc
	.long	0xa1
	.byte	0x30
	.uleb128 0x9
	.long	.LASF24
	.byte	0x6
	.byte	0xfd
	.long	0xa1
	.byte	0x38
	.uleb128 0x9
	.long	.LASF25
	.byte	0x6
	.byte	0xfe
	.long	0xa1
	.byte	0x40
	.uleb128 0xa
	.long	.LASF26
	.byte	0x6
	.value	0x100
	.long	0xa1
	.byte	0x48
	.uleb128 0xa
	.long	.LASF27
	.byte	0x6
	.value	0x101
	.long	0xa1
	.byte	0x50
	.uleb128 0xa
	.long	.LASF28
	.byte	0x6
	.value	0x102
	.long	0xa1
	.byte	0x58
	.uleb128 0xa
	.long	.LASF29
	.byte	0x6
	.value	0x104
	.long	0x285
	.byte	0x60
	.uleb128 0xa
	.long	.LASF30
	.byte	0x6
	.value	0x106
	.long	0x28b
	.byte	0x68
	.uleb128 0xa
	.long	.LASF31
	.byte	0x6
	.value	0x108
	.long	0x3f
	.byte	0x70
	.uleb128 0xa
	.long	.LASF32
	.byte	0x6
	.value	0x10c
	.long	0x3f
	.byte	0x74
	.uleb128 0xa
	.long	.LASF33
	.byte	0x6
	.value	0x10e
	.long	0x77
	.byte	0x78
	.uleb128 0xa
	.long	.LASF34
	.byte	0x6
	.value	0x112
	.long	0x62
	.byte	0x80
	.uleb128 0xa
	.long	.LASF35
	.byte	0x6
	.value	0x113
	.long	0x69
	.byte	0x82
	.uleb128 0xa
	.long	.LASF36
	.byte	0x6
	.value	0x114
	.long	0x291
	.byte	0x83
	.uleb128 0xa
	.long	.LASF37
	.byte	0x6
	.value	0x118
	.long	0x2a1
	.byte	0x88
	.uleb128 0xa
	.long	.LASF38
	.byte	0x6
	.value	0x121
	.long	0x82
	.byte	0x90
	.uleb128 0xa
	.long	.LASF39
	.byte	0x6
	.value	0x129
	.long	0x9f
	.byte	0x98
	.uleb128 0xa
	.long	.LASF40
	.byte	0x6
	.value	0x12a
	.long	0x9f
	.byte	0xa0
	.uleb128 0xa
	.long	.LASF41
	.byte	0x6
	.value	0x12b
	.long	0x9f
	.byte	0xa8
	.uleb128 0xa
	.long	.LASF42
	.byte	0x6
	.value	0x12c
	.long	0x9f
	.byte	0xb0
	.uleb128 0xa
	.long	.LASF43
	.byte	0x6
	.value	0x12e
	.long	0x2d
	.byte	0xb8
	.uleb128 0xa
	.long	.LASF44
	.byte	0x6
	.value	0x12f
	.long	0x3f
	.byte	0xc0
	.uleb128 0xa
	.long	.LASF45
	.byte	0x6
	.value	0x131
	.long	0x2a7
	.byte	0xc4
	.byte	0
	.uleb128 0xb
	.long	.LASF310
	.byte	0x6
	.byte	0x96
	.uleb128 0x8
	.long	.LASF47
	.byte	0x18
	.byte	0x6
	.byte	0x9c
	.long	0x285
	.uleb128 0x9
	.long	.LASF48
	.byte	0x6
	.byte	0x9d
	.long	0x285
	.byte	0
	.uleb128 0x9
	.long	.LASF49
	.byte	0x6
	.byte	0x9e
	.long	0x28b
	.byte	0x8
	.uleb128 0x9
	.long	.LASF50
	.byte	0x6
	.byte	0xa2
	.long	0x3f
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x254
	.uleb128 0x6
	.byte	0x8
	.long	0xd0
	.uleb128 0xc
	.long	0xa7
	.long	0x2a1
	.uleb128 0xd
	.long	0x8d
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x24d
	.uleb128 0xc
	.long	0xa7
	.long	0x2b7
	.uleb128 0xd
	.long	0x8d
	.byte	0x13
	.byte	0
	.uleb128 0xe
	.long	.LASF311
	.uleb128 0xf
	.long	.LASF51
	.byte	0x6
	.value	0x13b
	.long	0x2b7
	.uleb128 0xf
	.long	.LASF52
	.byte	0x6
	.value	0x13c
	.long	0x2b7
	.uleb128 0xf
	.long	.LASF53
	.byte	0x6
	.value	0x13d
	.long	0x2b7
	.uleb128 0x6
	.byte	0x8
	.long	0xae
	.uleb128 0x7
	.long	0x2e0
	.uleb128 0x10
	.long	.LASF54
	.byte	0x5
	.byte	0xaa
	.long	0x28b
	.uleb128 0x10
	.long	.LASF55
	.byte	0x5
	.byte	0xab
	.long	0x28b
	.uleb128 0x10
	.long	.LASF56
	.byte	0x5
	.byte	0xac
	.long	0x28b
	.uleb128 0x10
	.long	.LASF57
	.byte	0x7
	.byte	0x1a
	.long	0x3f
	.uleb128 0xc
	.long	0x2e6
	.long	0x322
	.uleb128 0x11
	.byte	0
	.uleb128 0x7
	.long	0x317
	.uleb128 0x10
	.long	.LASF58
	.byte	0x7
	.byte	0x1b
	.long	0x322
	.uleb128 0xf
	.long	.LASF59
	.byte	0x8
	.value	0x222
	.long	0x33e
	.uleb128 0x6
	.byte	0x8
	.long	0xa1
	.uleb128 0x12
	.byte	0x4
	.long	0x46
	.byte	0xa
	.byte	0x48
	.long	0x85b
	.uleb128 0x13
	.long	.LASF60
	.byte	0
	.uleb128 0x13
	.long	.LASF61
	.byte	0x1
	.uleb128 0x13
	.long	.LASF62
	.byte	0x2
	.uleb128 0x13
	.long	.LASF63
	.byte	0x3
	.uleb128 0x13
	.long	.LASF64
	.byte	0x4
	.uleb128 0x13
	.long	.LASF65
	.byte	0x5
	.uleb128 0x13
	.long	.LASF66
	.byte	0x6
	.uleb128 0x13
	.long	.LASF67
	.byte	0x7
	.uleb128 0x13
	.long	.LASF68
	.byte	0x8
	.uleb128 0x13
	.long	.LASF69
	.byte	0x9
	.uleb128 0x13
	.long	.LASF70
	.byte	0xa
	.uleb128 0x13
	.long	.LASF71
	.byte	0xb
	.uleb128 0x13
	.long	.LASF72
	.byte	0xc
	.uleb128 0x13
	.long	.LASF73
	.byte	0xd
	.uleb128 0x13
	.long	.LASF74
	.byte	0xe
	.uleb128 0x13
	.long	.LASF75
	.byte	0xf
	.uleb128 0x13
	.long	.LASF76
	.byte	0x10
	.uleb128 0x13
	.long	.LASF77
	.byte	0x11
	.uleb128 0x13
	.long	.LASF78
	.byte	0x12
	.uleb128 0x13
	.long	.LASF79
	.byte	0x13
	.uleb128 0x13
	.long	.LASF80
	.byte	0x14
	.uleb128 0x13
	.long	.LASF81
	.byte	0x15
	.uleb128 0x13
	.long	.LASF82
	.byte	0x16
	.uleb128 0x13
	.long	.LASF83
	.byte	0x17
	.uleb128 0x13
	.long	.LASF84
	.byte	0x18
	.uleb128 0x13
	.long	.LASF85
	.byte	0x19
	.uleb128 0x13
	.long	.LASF86
	.byte	0x1a
	.uleb128 0x13
	.long	.LASF87
	.byte	0x1b
	.uleb128 0x13
	.long	.LASF88
	.byte	0x1c
	.uleb128 0x13
	.long	.LASF89
	.byte	0x1d
	.uleb128 0x13
	.long	.LASF90
	.byte	0x1e
	.uleb128 0x13
	.long	.LASF91
	.byte	0x1f
	.uleb128 0x13
	.long	.LASF92
	.byte	0x20
	.uleb128 0x13
	.long	.LASF93
	.byte	0x21
	.uleb128 0x13
	.long	.LASF94
	.byte	0x22
	.uleb128 0x13
	.long	.LASF95
	.byte	0x23
	.uleb128 0x13
	.long	.LASF96
	.byte	0x24
	.uleb128 0x13
	.long	.LASF97
	.byte	0x25
	.uleb128 0x13
	.long	.LASF98
	.byte	0x26
	.uleb128 0x13
	.long	.LASF99
	.byte	0x27
	.uleb128 0x13
	.long	.LASF100
	.byte	0x28
	.uleb128 0x13
	.long	.LASF101
	.byte	0x29
	.uleb128 0x13
	.long	.LASF102
	.byte	0x2a
	.uleb128 0x13
	.long	.LASF103
	.byte	0x2b
	.uleb128 0x13
	.long	.LASF104
	.byte	0x2c
	.uleb128 0x13
	.long	.LASF105
	.byte	0x2d
	.uleb128 0x13
	.long	.LASF106
	.byte	0x2e
	.uleb128 0x13
	.long	.LASF107
	.byte	0x2f
	.uleb128 0x13
	.long	.LASF108
	.byte	0x30
	.uleb128 0x13
	.long	.LASF109
	.byte	0x31
	.uleb128 0x13
	.long	.LASF110
	.byte	0x32
	.uleb128 0x13
	.long	.LASF111
	.byte	0x33
	.uleb128 0x13
	.long	.LASF112
	.byte	0x34
	.uleb128 0x13
	.long	.LASF113
	.byte	0x35
	.uleb128 0x13
	.long	.LASF114
	.byte	0x36
	.uleb128 0x13
	.long	.LASF115
	.byte	0x37
	.uleb128 0x13
	.long	.LASF116
	.byte	0x38
	.uleb128 0x13
	.long	.LASF117
	.byte	0x39
	.uleb128 0x13
	.long	.LASF118
	.byte	0x3a
	.uleb128 0x13
	.long	.LASF119
	.byte	0x3b
	.uleb128 0x13
	.long	.LASF120
	.byte	0x3c
	.uleb128 0x13
	.long	.LASF121
	.byte	0x3c
	.uleb128 0x13
	.long	.LASF122
	.byte	0x3d
	.uleb128 0x13
	.long	.LASF123
	.byte	0x3e
	.uleb128 0x13
	.long	.LASF124
	.byte	0x3f
	.uleb128 0x13
	.long	.LASF125
	.byte	0x40
	.uleb128 0x13
	.long	.LASF126
	.byte	0x41
	.uleb128 0x13
	.long	.LASF127
	.byte	0x42
	.uleb128 0x13
	.long	.LASF128
	.byte	0x43
	.uleb128 0x13
	.long	.LASF129
	.byte	0x44
	.uleb128 0x13
	.long	.LASF130
	.byte	0x45
	.uleb128 0x13
	.long	.LASF131
	.byte	0x46
	.uleb128 0x13
	.long	.LASF132
	.byte	0x47
	.uleb128 0x13
	.long	.LASF133
	.byte	0x48
	.uleb128 0x13
	.long	.LASF134
	.byte	0x49
	.uleb128 0x13
	.long	.LASF135
	.byte	0x4a
	.uleb128 0x13
	.long	.LASF136
	.byte	0x4b
	.uleb128 0x13
	.long	.LASF137
	.byte	0x4c
	.uleb128 0x13
	.long	.LASF138
	.byte	0x4d
	.uleb128 0x13
	.long	.LASF139
	.byte	0x4e
	.uleb128 0x13
	.long	.LASF140
	.byte	0x4f
	.uleb128 0x13
	.long	.LASF141
	.byte	0x50
	.uleb128 0x13
	.long	.LASF142
	.byte	0x51
	.uleb128 0x13
	.long	.LASF143
	.byte	0x52
	.uleb128 0x13
	.long	.LASF144
	.byte	0x53
	.uleb128 0x13
	.long	.LASF145
	.byte	0x54
	.uleb128 0x13
	.long	.LASF146
	.byte	0x55
	.uleb128 0x13
	.long	.LASF147
	.byte	0x56
	.uleb128 0x13
	.long	.LASF148
	.byte	0x57
	.uleb128 0x13
	.long	.LASF149
	.byte	0x58
	.uleb128 0x13
	.long	.LASF150
	.byte	0x59
	.uleb128 0x13
	.long	.LASF151
	.byte	0x5a
	.uleb128 0x13
	.long	.LASF152
	.byte	0x5b
	.uleb128 0x13
	.long	.LASF153
	.byte	0x5c
	.uleb128 0x13
	.long	.LASF154
	.byte	0x5d
	.uleb128 0x13
	.long	.LASF155
	.byte	0x5e
	.uleb128 0x13
	.long	.LASF156
	.byte	0x5f
	.uleb128 0x13
	.long	.LASF157
	.byte	0x60
	.uleb128 0x13
	.long	.LASF158
	.byte	0x61
	.uleb128 0x13
	.long	.LASF159
	.byte	0x62
	.uleb128 0x13
	.long	.LASF160
	.byte	0x63
	.uleb128 0x13
	.long	.LASF161
	.byte	0x64
	.uleb128 0x13
	.long	.LASF162
	.byte	0x65
	.uleb128 0x13
	.long	.LASF163
	.byte	0x66
	.uleb128 0x13
	.long	.LASF164
	.byte	0x67
	.uleb128 0x13
	.long	.LASF165
	.byte	0x68
	.uleb128 0x13
	.long	.LASF166
	.byte	0x69
	.uleb128 0x13
	.long	.LASF167
	.byte	0x6a
	.uleb128 0x13
	.long	.LASF168
	.byte	0x6b
	.uleb128 0x13
	.long	.LASF169
	.byte	0x6c
	.uleb128 0x13
	.long	.LASF170
	.byte	0x6d
	.uleb128 0x13
	.long	.LASF171
	.byte	0x6e
	.uleb128 0x13
	.long	.LASF172
	.byte	0x6f
	.uleb128 0x13
	.long	.LASF173
	.byte	0x70
	.uleb128 0x13
	.long	.LASF174
	.byte	0x71
	.uleb128 0x13
	.long	.LASF175
	.byte	0x72
	.uleb128 0x13
	.long	.LASF176
	.byte	0x73
	.uleb128 0x13
	.long	.LASF177
	.byte	0x74
	.uleb128 0x13
	.long	.LASF178
	.byte	0x75
	.uleb128 0x13
	.long	.LASF179
	.byte	0x76
	.uleb128 0x13
	.long	.LASF180
	.byte	0x77
	.uleb128 0x13
	.long	.LASF181
	.byte	0x78
	.uleb128 0x13
	.long	.LASF182
	.byte	0x79
	.uleb128 0x13
	.long	.LASF183
	.byte	0x7a
	.uleb128 0x13
	.long	.LASF184
	.byte	0x7b
	.uleb128 0x13
	.long	.LASF185
	.byte	0x7c
	.uleb128 0x13
	.long	.LASF186
	.byte	0x7d
	.uleb128 0x13
	.long	.LASF187
	.byte	0x7e
	.uleb128 0x13
	.long	.LASF188
	.byte	0x7f
	.uleb128 0x13
	.long	.LASF189
	.byte	0x80
	.uleb128 0x13
	.long	.LASF190
	.byte	0x81
	.uleb128 0x13
	.long	.LASF191
	.byte	0x82
	.uleb128 0x13
	.long	.LASF192
	.byte	0x83
	.uleb128 0x13
	.long	.LASF193
	.byte	0x84
	.uleb128 0x13
	.long	.LASF194
	.byte	0x85
	.uleb128 0x13
	.long	.LASF195
	.byte	0x86
	.uleb128 0x13
	.long	.LASF196
	.byte	0x87
	.uleb128 0x13
	.long	.LASF197
	.byte	0x88
	.uleb128 0x13
	.long	.LASF198
	.byte	0x89
	.uleb128 0x13
	.long	.LASF199
	.byte	0x8a
	.uleb128 0x13
	.long	.LASF200
	.byte	0x8b
	.uleb128 0x13
	.long	.LASF201
	.byte	0x8c
	.uleb128 0x13
	.long	.LASF202
	.byte	0x8d
	.uleb128 0x13
	.long	.LASF203
	.byte	0x8e
	.uleb128 0x13
	.long	.LASF204
	.byte	0x8f
	.uleb128 0x13
	.long	.LASF205
	.byte	0x90
	.uleb128 0x13
	.long	.LASF206
	.byte	0x91
	.uleb128 0x13
	.long	.LASF207
	.byte	0x92
	.uleb128 0x13
	.long	.LASF208
	.byte	0x93
	.uleb128 0x13
	.long	.LASF209
	.byte	0x94
	.uleb128 0x13
	.long	.LASF210
	.byte	0x95
	.uleb128 0x13
	.long	.LASF211
	.byte	0x96
	.uleb128 0x13
	.long	.LASF212
	.byte	0x97
	.uleb128 0x13
	.long	.LASF213
	.byte	0x98
	.uleb128 0x13
	.long	.LASF214
	.byte	0x99
	.uleb128 0x13
	.long	.LASF215
	.byte	0x9a
	.uleb128 0x13
	.long	.LASF216
	.byte	0x9b
	.uleb128 0x13
	.long	.LASF217
	.byte	0x9c
	.uleb128 0x13
	.long	.LASF218
	.byte	0x9d
	.uleb128 0x13
	.long	.LASF219
	.byte	0x9e
	.uleb128 0x13
	.long	.LASF220
	.byte	0x9f
	.uleb128 0x13
	.long	.LASF221
	.byte	0xa0
	.uleb128 0x13
	.long	.LASF222
	.byte	0xa1
	.uleb128 0x13
	.long	.LASF223
	.byte	0xa2
	.uleb128 0x13
	.long	.LASF224
	.byte	0xa3
	.uleb128 0x13
	.long	.LASF225
	.byte	0xa4
	.uleb128 0x13
	.long	.LASF226
	.byte	0xa5
	.uleb128 0x13
	.long	.LASF227
	.byte	0xa6
	.uleb128 0x13
	.long	.LASF228
	.byte	0xa7
	.uleb128 0x13
	.long	.LASF229
	.byte	0xa8
	.uleb128 0x13
	.long	.LASF230
	.byte	0xa9
	.uleb128 0x13
	.long	.LASF231
	.byte	0xaa
	.uleb128 0x13
	.long	.LASF232
	.byte	0xab
	.uleb128 0x13
	.long	.LASF233
	.byte	0xac
	.uleb128 0x13
	.long	.LASF234
	.byte	0xad
	.uleb128 0x13
	.long	.LASF235
	.byte	0xae
	.uleb128 0x13
	.long	.LASF236
	.byte	0xaf
	.uleb128 0x13
	.long	.LASF237
	.byte	0xb0
	.uleb128 0x13
	.long	.LASF238
	.byte	0xb1
	.uleb128 0x13
	.long	.LASF239
	.byte	0xb2
	.uleb128 0x13
	.long	.LASF240
	.byte	0xb3
	.uleb128 0x13
	.long	.LASF241
	.byte	0xb4
	.uleb128 0x13
	.long	.LASF242
	.byte	0xb5
	.uleb128 0x13
	.long	.LASF243
	.byte	0xb6
	.uleb128 0x13
	.long	.LASF244
	.byte	0xb7
	.uleb128 0x13
	.long	.LASF245
	.byte	0xb8
	.uleb128 0x13
	.long	.LASF246
	.byte	0xb9
	.uleb128 0x13
	.long	.LASF247
	.byte	0xba
	.uleb128 0x13
	.long	.LASF248
	.byte	0xbb
	.uleb128 0x13
	.long	.LASF249
	.byte	0xbc
	.uleb128 0x13
	.long	.LASF250
	.byte	0xbd
	.uleb128 0x13
	.long	.LASF251
	.byte	0xbe
	.uleb128 0x13
	.long	.LASF252
	.byte	0xbf
	.uleb128 0x13
	.long	.LASF253
	.byte	0xc0
	.uleb128 0x13
	.long	.LASF254
	.byte	0xc1
	.uleb128 0x13
	.long	.LASF255
	.byte	0xc2
	.uleb128 0x13
	.long	.LASF256
	.byte	0xc3
	.uleb128 0x13
	.long	.LASF257
	.byte	0xc4
	.uleb128 0x13
	.long	.LASF258
	.byte	0xc5
	.uleb128 0x13
	.long	.LASF259
	.byte	0xc6
	.uleb128 0x13
	.long	.LASF260
	.byte	0xc7
	.uleb128 0x13
	.long	.LASF261
	.byte	0xeb
	.uleb128 0x13
	.long	.LASF262
	.byte	0xec
	.uleb128 0x13
	.long	.LASF263
	.byte	0xed
	.uleb128 0x13
	.long	.LASF264
	.byte	0xee
	.uleb128 0x13
	.long	.LASF265
	.byte	0xef
	.uleb128 0x13
	.long	.LASF266
	.byte	0xf0
	.uleb128 0x13
	.long	.LASF267
	.byte	0xf1
	.uleb128 0x13
	.long	.LASF268
	.byte	0xf2
	.uleb128 0x13
	.long	.LASF269
	.byte	0xf3
	.uleb128 0x13
	.long	.LASF270
	.byte	0xf4
	.uleb128 0x13
	.long	.LASF271
	.byte	0xf5
	.uleb128 0x13
	.long	.LASF272
	.byte	0xf6
	.uleb128 0x13
	.long	.LASF273
	.byte	0xf7
	.uleb128 0x13
	.long	.LASF274
	.byte	0xf8
	.byte	0
	.uleb128 0x10
	.long	.LASF275
	.byte	0x9
	.byte	0x39
	.long	0xa1
	.uleb128 0x10
	.long	.LASF276
	.byte	0x9
	.byte	0x47
	.long	0x3f
	.uleb128 0x10
	.long	.LASF277
	.byte	0x9
	.byte	0x4c
	.long	0x3f
	.uleb128 0x10
	.long	.LASF278
	.byte	0x9
	.byte	0x50
	.long	0x3f
	.uleb128 0xc
	.long	0xa1
	.long	0x897
	.uleb128 0xd
	.long	0x8d
	.byte	0x1
	.byte	0
	.uleb128 0xf
	.long	.LASF279
	.byte	0x4
	.value	0x11a
	.long	0x887
	.uleb128 0xf
	.long	.LASF280
	.byte	0x4
	.value	0x11b
	.long	0x3f
	.uleb128 0xf
	.long	.LASF281
	.byte	0x4
	.value	0x11c
	.long	0x4d
	.uleb128 0xf
	.long	.LASF282
	.byte	0x4
	.value	0x121
	.long	0x887
	.uleb128 0xf
	.long	.LASF283
	.byte	0x4
	.value	0x129
	.long	0x3f
	.uleb128 0xf
	.long	.LASF284
	.byte	0x4
	.value	0x12a
	.long	0x4d
	.uleb128 0xc
	.long	0x3f
	.long	0x8f5
	.uleb128 0xd
	.long	0x8d
	.byte	0xa
	.uleb128 0xd
	.long	0x8d
	.byte	0x63
	.byte	0
	.uleb128 0x14
	.long	.LASF285
	.byte	0x1
	.byte	0x11
	.long	0x8df
	.uleb128 0x9
	.byte	0x3
	.quad	aGrades
	.uleb128 0x14
	.long	.LASF286
	.byte	0x1
	.byte	0x12
	.long	0x8df
	.uleb128 0x9
	.byte	0x3
	.quad	bGrades
	.uleb128 0xc
	.long	0xa7
	.long	0x930
	.uleb128 0x15
	.long	0x8d
	.value	0x13ff
	.byte	0
	.uleb128 0x14
	.long	.LASF287
	.byte	0x1
	.byte	0x13
	.long	0x91f
	.uleb128 0x9
	.byte	0x3
	.quad	retBufferArea
	.uleb128 0x14
	.long	.LASF288
	.byte	0x1
	.byte	0x14
	.long	0xa1
	.uleb128 0x9
	.byte	0x3
	.quad	retBuffer
	.uleb128 0x14
	.long	.LASF289
	.byte	0x1
	.byte	0x16
	.long	0x96f
	.uleb128 0x9
	.byte	0x3
	.quad	txtFile
	.uleb128 0x6
	.byte	0x8
	.long	0xc5
	.uleb128 0x16
	.long	.LASF292
	.byte	0x1
	.byte	0x6e
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x9ca
	.uleb128 0x17
	.long	.LASF290
	.byte	0x1
	.byte	0x6e
	.long	0x9da
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x18
	.string	"n"
	.byte	0x1
	.byte	0x6e
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0x17
	.long	.LASF291
	.byte	0x1
	.byte	0x6e
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x19
	.string	"s"
	.byte	0x1
	.byte	0x6f
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.byte	0
	.uleb128 0xc
	.long	0x3f
	.long	0x9da
	.uleb128 0xd
	.long	0x8d
	.byte	0x63
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x9ca
	.uleb128 0x1a
	.long	.LASF293
	.byte	0x1
	.byte	0x64
	.long	0xa1
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0xa11
	.uleb128 0x1b
	.long	.LASF294
	.byte	0x1
	.byte	0x65
	.long	0xa11
	.uleb128 0x3
	.byte	0x91
	.sleb128 -272
	.byte	0
	.uleb128 0xc
	.long	0xa7
	.long	0xa21
	.uleb128 0xd
	.long	0x8d
	.byte	0xff
	.byte	0
	.uleb128 0x1c
	.long	.LASF295
	.byte	0x1
	.byte	0x4f
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0xa9d
	.uleb128 0x17
	.long	.LASF290
	.byte	0x1
	.byte	0x4f
	.long	0x9da
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x18
	.string	"n"
	.byte	0x1
	.byte	0x4f
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.uleb128 0x19
	.string	"s"
	.byte	0x1
	.byte	0x50
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1b
	.long	.LASF296
	.byte	0x1
	.byte	0x51
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x1b
	.long	.LASF297
	.byte	0x1
	.byte	0x52
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x1b
	.long	.LASF298
	.byte	0x1
	.byte	0x53
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1b
	.long	.LASF299
	.byte	0x1
	.byte	0x54
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.byte	0
	.uleb128 0x1d
	.long	.LASF300
	.byte	0x1
	.byte	0x3d
	.long	0xa7
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0xacb
	.uleb128 0x19
	.string	"a"
	.byte	0x1
	.byte	0x3e
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x1e
	.long	.LASF301
	.byte	0x1
	.byte	0x18
	.long	0x3f
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x17
	.long	.LASF302
	.byte	0x1
	.byte	0x18
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x17
	.long	.LASF303
	.byte	0x1
	.byte	0x18
	.long	0x33e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x1b
	.long	.LASF304
	.byte	0x1
	.byte	0x19
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x19
	.string	"t"
	.byte	0x1
	.byte	0x1a
	.long	0xb3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x1b
	.long	.LASF305
	.byte	0x1
	.byte	0x1c
	.long	0x4d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x1f
	.quad	.LBB2
	.quad	.LBE2-.LBB2
	.uleb128 0x1b
	.long	.LASF306
	.byte	0x1
	.byte	0x25
	.long	0x46
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x4
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF142:
	.string	"_SC_THREAD_PRIO_PROTECT"
.LASF36:
	.string	"_shortbuf"
.LASF310:
	.string	"_IO_lock_t"
.LASF89:
	.string	"_SC_VERSION"
.LASF183:
	.string	"_SC_NL_NMAX"
.LASF56:
	.string	"stderr"
.LASF25:
	.string	"_IO_buf_end"
.LASF74:
	.string	"_SC_SYNCHRONIZED_IO"
.LASF140:
	.string	"_SC_THREAD_PRIORITY_SCHEDULING"
.LASF145:
	.string	"_SC_NPROCESSORS_ONLN"
.LASF278:
	.string	"optopt"
.LASF141:
	.string	"_SC_THREAD_PRIO_INHERIT"
.LASF79:
	.string	"_SC_MEMORY_PROTECTION"
.LASF234:
	.string	"_SC_SYMLOOP_MAX"
.LASF225:
	.string	"_SC_TIMEOUTS"
.LASF195:
	.string	"_SC_BASE"
.LASF124:
	.string	"_SC_PII_OSI_COTS"
.LASF210:
	.string	"_SC_MONOTONIC_CLOCK"
.LASF129:
	.string	"_SC_THREAD_SAFE_FUNCTIONS"
.LASF23:
	.string	"_IO_write_end"
.LASF1:
	.string	"unsigned int"
.LASF307:
	.string	"GNU C11 6.3.0 20170516 -mtune=generic -march=x86-64 -g -O0"
.LASF65:
	.string	"_SC_STREAM_MAX"
.LASF287:
	.string	"retBufferArea"
.LASF115:
	.string	"_SC_PII_SOCKET"
.LASF73:
	.string	"_SC_PRIORITIZED_IO"
.LASF302:
	.string	"argc"
.LASF17:
	.string	"_flags"
.LASF237:
	.string	"_SC_V6_ILP32_OFF32"
.LASF222:
	.string	"_SC_THREAD_SPORADIC_SERVER"
.LASF175:
	.string	"_SC_SHRT_MIN"
.LASF179:
	.string	"_SC_USHRT_MAX"
.LASF185:
	.string	"_SC_NL_TEXTMAX"
.LASF29:
	.string	"_markers"
.LASF134:
	.string	"_SC_THREAD_DESTRUCTOR_ITERATIONS"
.LASF206:
	.string	"_SC_PIPE"
.LASF97:
	.string	"_SC_BC_DIM_MAX"
.LASF76:
	.string	"_SC_MAPPED_FILES"
.LASF107:
	.string	"_SC_2_C_BIND"
.LASF87:
	.string	"_SC_MQ_OPEN_MAX"
.LASF155:
	.string	"_SC_XOPEN_SHM"
.LASF165:
	.string	"_SC_INT_MAX"
.LASF109:
	.string	"_SC_2_FORT_DEV"
.LASF159:
	.string	"_SC_XOPEN_XPG2"
.LASF160:
	.string	"_SC_XOPEN_XPG3"
.LASF161:
	.string	"_SC_XOPEN_XPG4"
.LASF116:
	.string	"_SC_PII_INTERNET"
.LASF265:
	.string	"_SC_V7_LP64_OFF64"
.LASF86:
	.string	"_SC_DELAYTIMER_MAX"
.LASF169:
	.string	"_SC_MB_LEN_MAX"
.LASF221:
	.string	"_SC_SPORADIC_SERVER"
.LASF148:
	.string	"_SC_ATEXIT_MAX"
.LASF281:
	.string	"__timezone"
.LASF69:
	.string	"_SC_REALTIME_SIGNALS"
.LASF203:
	.string	"_SC_DEVICE_SPECIFIC_R"
.LASF50:
	.string	"_pos"
.LASF143:
	.string	"_SC_THREAD_PROCESS_SHARED"
.LASF68:
	.string	"_SC_SAVED_IDS"
.LASF55:
	.string	"stdout"
.LASF197:
	.string	"_SC_C_LANG_SUPPORT_R"
.LASF28:
	.string	"_IO_save_end"
.LASF108:
	.string	"_SC_2_C_DEV"
.LASF189:
	.string	"_SC_XBS5_LPBIG_OFFBIG"
.LASF285:
	.string	"aGrades"
.LASF157:
	.string	"_SC_2_C_VERSION"
.LASF309:
	.string	"/home/sozden1/cs220/proj4/a"
.LASF172:
	.string	"_SC_SCHAR_MAX"
.LASF243:
	.string	"_SC_TRACE_EVENT_FILTER"
.LASF171:
	.string	"_SC_SSIZE_MAX"
.LASF158:
	.string	"_SC_2_UPE"
.LASF306:
	.string	"seed"
.LASF261:
	.string	"_SC_IPV6"
.LASF96:
	.string	"_SC_BC_BASE_MAX"
.LASF15:
	.string	"long long unsigned int"
.LASF118:
	.string	"_SC_POLL"
.LASF191:
	.string	"_SC_XOPEN_REALTIME"
.LASF224:
	.string	"_SC_SYSTEM_DATABASE_R"
.LASF298:
	.string	"avgQuiz"
.LASF163:
	.string	"_SC_CHAR_MAX"
.LASF58:
	.string	"sys_errlist"
.LASF27:
	.string	"_IO_backup_base"
.LASF38:
	.string	"_offset"
.LASF247:
	.string	"_SC_LEVEL1_ICACHE_ASSOC"
.LASF214:
	.string	"_SC_READER_WRITER_LOCKS"
.LASF57:
	.string	"sys_nerr"
.LASF245:
	.string	"_SC_TRACE_LOG"
.LASF31:
	.string	"_fileno"
.LASF288:
	.string	"retBuffer"
.LASF299:
	.string	"avgTest"
.LASF277:
	.string	"opterr"
.LASF200:
	.string	"_SC_THREAD_CPUTIME"
.LASF270:
	.string	"_SC_TRACE_SYS_MAX"
.LASF187:
	.string	"_SC_XBS5_ILP32_OFFBIG"
.LASF123:
	.string	"_SC_PII_INTERNET_DGRAM"
.LASF8:
	.string	"size_t"
.LASF233:
	.string	"_SC_2_PBS_TRACK"
.LASF308:
	.string	"grades.c"
.LASF207:
	.string	"_SC_FILE_ATTRIBUTES"
.LASF72:
	.string	"_SC_ASYNCHRONOUS_IO"
.LASF75:
	.string	"_SC_FSYNC"
.LASF20:
	.string	"_IO_read_base"
.LASF250:
	.string	"_SC_LEVEL1_DCACHE_ASSOC"
.LASF202:
	.string	"_SC_DEVICE_SPECIFIC"
.LASF54:
	.string	"stdin"
.LASF48:
	.string	"_next"
.LASF167:
	.string	"_SC_LONG_BIT"
.LASF92:
	.string	"_SC_SEM_NSEMS_MAX"
.LASF101:
	.string	"_SC_EQUIV_CLASS_MAX"
.LASF272:
	.string	"_SC_XOPEN_STREAMS"
.LASF248:
	.string	"_SC_LEVEL1_ICACHE_LINESIZE"
.LASF217:
	.string	"_SC_REGEX_VERSION"
.LASF230:
	.string	"_SC_2_PBS_ACCOUNTING"
.LASF303:
	.string	"argv"
.LASF84:
	.string	"_SC_AIO_MAX"
.LASF254:
	.string	"_SC_LEVEL2_CACHE_LINESIZE"
.LASF150:
	.string	"_SC_XOPEN_VERSION"
.LASF218:
	.string	"_SC_SHELL"
.LASF66:
	.string	"_SC_TZNAME_MAX"
.LASF13:
	.string	"char"
.LASF44:
	.string	"_mode"
.LASF280:
	.string	"__daylight"
.LASF78:
	.string	"_SC_MEMLOCK_RANGE"
.LASF147:
	.string	"_SC_AVPHYS_PAGES"
.LASF112:
	.string	"_SC_2_LOCALEDEF"
.LASF282:
	.string	"tzname"
.LASF264:
	.string	"_SC_V7_ILP32_OFFBIG"
.LASF47:
	.string	"_IO_marker"
.LASF18:
	.string	"_IO_read_ptr"
.LASF266:
	.string	"_SC_V7_LPBIG_OFFBIG"
.LASF256:
	.string	"_SC_LEVEL3_CACHE_ASSOC"
.LASF209:
	.string	"_SC_FILE_SYSTEM"
.LASF14:
	.string	"time_t"
.LASF259:
	.string	"_SC_LEVEL4_CACHE_ASSOC"
.LASF238:
	.string	"_SC_V6_ILP32_OFFBIG"
.LASF94:
	.string	"_SC_SIGQUEUE_MAX"
.LASF220:
	.string	"_SC_SPAWN"
.LASF201:
	.string	"_SC_DEVICE_IO"
.LASF240:
	.string	"_SC_V6_LPBIG_OFFBIG"
.LASF106:
	.string	"_SC_2_VERSION"
.LASF258:
	.string	"_SC_LEVEL4_CACHE_SIZE"
.LASF305:
	.string	"pagesize"
.LASF21:
	.string	"_IO_write_base"
.LASF295:
	.string	"getAvg"
.LASF293:
	.string	"getUserLine"
.LASF235:
	.string	"_SC_STREAMS"
.LASF51:
	.string	"_IO_2_1_stdin_"
.LASF3:
	.string	"long long int"
.LASF52:
	.string	"_IO_2_1_stdout_"
.LASF228:
	.string	"_SC_USER_GROUPS_R"
.LASF26:
	.string	"_IO_save_base"
.LASF103:
	.string	"_SC_LINE_MAX"
.LASF199:
	.string	"_SC_CPUTIME"
.LASF276:
	.string	"optind"
.LASF120:
	.string	"_SC_UIO_MAXIOV"
.LASF241:
	.string	"_SC_HOST_NAME_MAX"
.LASF196:
	.string	"_SC_C_LANG_SUPPORT"
.LASF135:
	.string	"_SC_THREAD_KEYS_MAX"
.LASF136:
	.string	"_SC_THREAD_STACK_MIN"
.LASF81:
	.string	"_SC_SEMAPHORES"
.LASF177:
	.string	"_SC_UINT_MAX"
.LASF61:
	.string	"_SC_CHILD_MAX"
.LASF294:
	.string	"buffer"
.LASF127:
	.string	"_SC_T_IOV_MAX"
.LASF63:
	.string	"_SC_NGROUPS_MAX"
.LASF212:
	.string	"_SC_SINGLE_PROCESS"
.LASF153:
	.string	"_SC_XOPEN_CRYPT"
.LASF300:
	.string	"getGrades"
.LASF257:
	.string	"_SC_LEVEL3_CACHE_LINESIZE"
.LASF133:
	.string	"_SC_TTY_NAME_MAX"
.LASF39:
	.string	"__pad1"
.LASF40:
	.string	"__pad2"
.LASF41:
	.string	"__pad3"
.LASF42:
	.string	"__pad4"
.LASF43:
	.string	"__pad5"
.LASF289:
	.string	"txtFile"
.LASF114:
	.string	"_SC_PII_XTI"
.LASF162:
	.string	"_SC_CHAR_BIT"
.LASF249:
	.string	"_SC_LEVEL1_DCACHE_SIZE"
.LASF297:
	.string	"minProj"
.LASF35:
	.string	"_vtable_offset"
.LASF198:
	.string	"_SC_CLOCK_SELECTION"
.LASF77:
	.string	"_SC_MEMLOCK"
.LASF67:
	.string	"_SC_JOB_CONTROL"
.LASF62:
	.string	"_SC_CLK_TCK"
.LASF262:
	.string	"_SC_RAW_SOCKETS"
.LASF275:
	.string	"optarg"
.LASF193:
	.string	"_SC_ADVISORY_INFO"
.LASF71:
	.string	"_SC_TIMERS"
.LASF194:
	.string	"_SC_BARRIERS"
.LASF98:
	.string	"_SC_BC_SCALE_MAX"
.LASF178:
	.string	"_SC_ULONG_MAX"
.LASF88:
	.string	"_SC_MQ_PRIO_MAX"
.LASF242:
	.string	"_SC_TRACE"
.LASF255:
	.string	"_SC_LEVEL3_CACHE_SIZE"
.LASF215:
	.string	"_SC_SPIN_LOCKS"
.LASF251:
	.string	"_SC_LEVEL1_DCACHE_LINESIZE"
.LASF99:
	.string	"_SC_BC_STRING_MAX"
.LASF144:
	.string	"_SC_NPROCESSORS_CONF"
.LASF166:
	.string	"_SC_INT_MIN"
.LASF263:
	.string	"_SC_V7_ILP32_OFF32"
.LASF19:
	.string	"_IO_read_end"
.LASF204:
	.string	"_SC_FD_MGMT"
.LASF216:
	.string	"_SC_REGEXP"
.LASF7:
	.string	"short int"
.LASF246:
	.string	"_SC_LEVEL1_ICACHE_SIZE"
.LASF104:
	.string	"_SC_RE_DUP_MAX"
.LASF90:
	.string	"_SC_PAGESIZE"
.LASF2:
	.string	"long int"
.LASF174:
	.string	"_SC_SHRT_MAX"
.LASF188:
	.string	"_SC_XBS5_LP64_OFF64"
.LASF223:
	.string	"_SC_SYSTEM_DATABASE"
.LASF192:
	.string	"_SC_XOPEN_REALTIME_THREADS"
.LASF274:
	.string	"_SC_THREAD_ROBUST_PRIO_PROTECT"
.LASF156:
	.string	"_SC_2_CHAR_TERM"
.LASF149:
	.string	"_SC_PASS_MAX"
.LASF205:
	.string	"_SC_FIFO"
.LASF60:
	.string	"_SC_ARG_MAX"
.LASF252:
	.string	"_SC_LEVEL2_CACHE_SIZE"
.LASF236:
	.string	"_SC_2_PBS_CHECKPOINT"
.LASF59:
	.string	"__environ"
.LASF304:
	.string	"secID"
.LASF110:
	.string	"_SC_2_FORT_RUN"
.LASF311:
	.string	"_IO_FILE_plus"
.LASF93:
	.string	"_SC_SEM_VALUE_MAX"
.LASF139:
	.string	"_SC_THREAD_ATTR_STACKSIZE"
.LASF83:
	.string	"_SC_AIO_LISTIO_MAX"
.LASF273:
	.string	"_SC_THREAD_ROBUST_PRIO_INHERIT"
.LASF128:
	.string	"_SC_THREADS"
.LASF113:
	.string	"_SC_PII"
.LASF244:
	.string	"_SC_TRACE_INHERIT"
.LASF168:
	.string	"_SC_WORD_BIT"
.LASF186:
	.string	"_SC_XBS5_ILP32_OFF32"
.LASF126:
	.string	"_SC_PII_OSI_M"
.LASF111:
	.string	"_SC_2_SW_DEV"
.LASF292:
	.string	"printGrades"
.LASF37:
	.string	"_lock"
.LASF164:
	.string	"_SC_CHAR_MIN"
.LASF286:
	.string	"bGrades"
.LASF11:
	.string	"sizetype"
.LASF152:
	.string	"_SC_XOPEN_UNIX"
.LASF0:
	.string	"long unsigned int"
.LASF33:
	.string	"_old_offset"
.LASF117:
	.string	"_SC_PII_OSI"
.LASF46:
	.string	"_IO_FILE"
.LASF176:
	.string	"_SC_UCHAR_MAX"
.LASF284:
	.string	"timezone"
.LASF173:
	.string	"_SC_SCHAR_MIN"
.LASF70:
	.string	"_SC_PRIORITY_SCHEDULING"
.LASF119:
	.string	"_SC_SELECT"
.LASF213:
	.string	"_SC_NETWORKING"
.LASF95:
	.string	"_SC_TIMER_MAX"
.LASF268:
	.string	"_SC_TRACE_EVENT_NAME_MAX"
.LASF239:
	.string	"_SC_V6_LP64_OFF64"
.LASF130:
	.string	"_SC_GETGR_R_SIZE_MAX"
.LASF4:
	.string	"unsigned char"
.LASF132:
	.string	"_SC_LOGIN_NAME_MAX"
.LASF102:
	.string	"_SC_EXPR_NEST_MAX"
.LASF279:
	.string	"__tzname"
.LASF49:
	.string	"_sbuf"
.LASF122:
	.string	"_SC_PII_INTERNET_STREAM"
.LASF22:
	.string	"_IO_write_ptr"
.LASF267:
	.string	"_SC_SS_REPL_MAX"
.LASF121:
	.string	"_SC_IOV_MAX"
.LASF291:
	.string	"first"
.LASF260:
	.string	"_SC_LEVEL4_CACHE_LINESIZE"
.LASF219:
	.string	"_SC_SIGNALS"
.LASF80:
	.string	"_SC_MESSAGE_PASSING"
.LASF12:
	.string	"__time_t"
.LASF296:
	.string	"avgProj"
.LASF82:
	.string	"_SC_SHARED_MEMORY_OBJECTS"
.LASF105:
	.string	"_SC_CHARCLASS_NAME_MAX"
.LASF125:
	.string	"_SC_PII_OSI_CLTS"
.LASF290:
	.string	"grds"
.LASF226:
	.string	"_SC_TYPED_MEMORY_OBJECTS"
.LASF283:
	.string	"daylight"
.LASF229:
	.string	"_SC_2_PBS"
.LASF146:
	.string	"_SC_PHYS_PAGES"
.LASF9:
	.string	"__off_t"
.LASF211:
	.string	"_SC_MULTI_PROCESS"
.LASF253:
	.string	"_SC_LEVEL2_CACHE_ASSOC"
.LASF6:
	.string	"signed char"
.LASF64:
	.string	"_SC_OPEN_MAX"
.LASF5:
	.string	"short unsigned int"
.LASF137:
	.string	"_SC_THREAD_THREADS_MAX"
.LASF301:
	.string	"main"
.LASF170:
	.string	"_SC_NZERO"
.LASF131:
	.string	"_SC_GETPW_R_SIZE_MAX"
.LASF232:
	.string	"_SC_2_PBS_MESSAGE"
.LASF91:
	.string	"_SC_RTSIG_MAX"
.LASF138:
	.string	"_SC_THREAD_ATTR_STACKADDR"
.LASF208:
	.string	"_SC_FILE_LOCKING"
.LASF269:
	.string	"_SC_TRACE_NAME_MAX"
.LASF100:
	.string	"_SC_COLL_WEIGHTS_MAX"
.LASF154:
	.string	"_SC_XOPEN_ENH_I18N"
.LASF190:
	.string	"_SC_XOPEN_LEGACY"
.LASF30:
	.string	"_chain"
.LASF182:
	.string	"_SC_NL_MSGMAX"
.LASF181:
	.string	"_SC_NL_LANGMAX"
.LASF16:
	.string	"FILE"
.LASF32:
	.string	"_flags2"
.LASF227:
	.string	"_SC_USER_GROUPS"
.LASF231:
	.string	"_SC_2_PBS_LOCATE"
.LASF184:
	.string	"_SC_NL_SETMAX"
.LASF34:
	.string	"_cur_column"
.LASF180:
	.string	"_SC_NL_ARGMAX"
.LASF53:
	.string	"_IO_2_1_stderr_"
.LASF271:
	.string	"_SC_TRACE_USER_EVENT_MAX"
.LASF10:
	.string	"__off64_t"
.LASF45:
	.string	"_unused2"
.LASF24:
	.string	"_IO_buf_base"
.LASF85:
	.string	"_SC_AIO_PRIO_DELTA_MAX"
.LASF151:
	.string	"_SC_XOPEN_XCU_VERSION"
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
