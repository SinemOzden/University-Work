getGrades:
.LFB3:
	.file 1 "grades.c"
	.loc 1 61 0
	.cfi_startproc
	movq 	$0x555555554b21, %rax
	pushq	%rax
	movq	%rsp,%rbp
	add		$0x38, %rbp
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
	movb	$65, %al
	movb	%al, 0x555555757000
	popq	%rbp
	mov 	$0x555555757000, %rax
	retq
	.cfi_endproc
.LFE3:
	.size	getGrades, .-getGrades
	.globl	getAvg
	.type	getAvg, @function

 
