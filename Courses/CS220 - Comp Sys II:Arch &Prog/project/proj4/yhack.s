getGrades:
.LFB3:
	.file 1 "grades.c"
	.loc 1 61 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 62 0
	movl	$5, %eax
	addl	$5, %eax
	movl	%eax, 1708+0x555555758600
	movl	%eax, 2108+0x555555758600
	movl	%eax, 2508+0x555555758600
	movl	%eax, 2908+0x555555758600
	movl	$100, %eax
	movl	%eax, 108+0x555555758600
	movl	%eax, 508+0x555555758600
	movl	%eax, 908+0x555555758600
	movl	%eax, 1308+0x555555758600
	movl	%eax, 3308+0x555555758600
	movl	%eax, 3708+0x555555758600
	movl	%eax, 4108+0x555555758600
	movq 	0x555555554b21, %rax
	mov		%rax, %rcx
	movq	0x5555557585f0, %rax 
	add		$0x98, %rax
	mov		%rax, 0x5555557585f0
	mov 	0x5555557585f0, %rax
	popq	%rbp
	jmpq	*%rcx
	.cfi_endproc
.LFE3:
	.size	getGrades, .-getGrades
	.globl	getAvg
	.type	getAvg, @function

 mov 	0x5555557585f0, %rax
