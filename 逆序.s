	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	%edi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	leaq	L_.str(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	leaq	-28(%rbp), %rsi
	movb	%dl, %al
	callq	_scanf
	movl	-28(%rbp), %edi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	callq	_getBit
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	movq	%rsp, %r8
	movq	%r8, -40(%rbp)
	leaq	15(,%rsi,4), %r8
	andq	$-16, %r8
	movq	%r8, %rax
	movq	%rsi, -72(%rbp)         ## 8-byte Spill
	callq	____chkstk_darwin
	subq	%rax, %rsp
	movq	%rsp, %rax
	movq	-72(%rbp), %rsi         ## 8-byte Reload
	movq	%rsi, -48(%rbp)
	movl	$0, -52(%rbp)
	movq	%rax, -80(%rbp)         ## 8-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-52(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-28(%rbp), %eax
	cltd
	movl	$10, %ecx
	idivl	%ecx
	movslq	-52(%rbp), %rsi
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movl	%edx, (%rdi,%rsi,4)
	movl	-28(%rbp), %edx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	%eax, -28(%rbp)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	$0, -56(%rbp)
	movl	$0, -60(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	movl	-60(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	LBB0_14
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=1
	movslq	-60(%rbp), %rax
	movq	-80(%rbp), %rcx         ## 8-byte Reload
	cmpl	$0, (%rcx,%rax,4)
	jne	LBB0_9
## %bb.7:                               ##   in Loop: Header=BB0_5 Depth=1
	cmpl	$0, -56(%rbp)
	jne	LBB0_9
## %bb.8:                               ##   in Loop: Header=BB0_5 Depth=1
	jmp	LBB0_13
LBB0_9:                                 ##   in Loop: Header=BB0_5 Depth=1
	movslq	-60(%rbp), %rax
	movq	-80(%rbp), %rcx         ## 8-byte Reload
	cmpl	$0, (%rcx,%rax,4)
	je	LBB0_11
## %bb.10:                              ##   in Loop: Header=BB0_5 Depth=1
	movl	$1, -56(%rbp)
	movslq	-60(%rbp), %rax
	movq	-80(%rbp), %rcx         ## 8-byte Reload
	movl	(%rcx,%rax,4), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	jmp	LBB0_12
LBB0_11:                                ##   in Loop: Header=BB0_5 Depth=1
	movslq	-60(%rbp), %rax
	movq	-80(%rbp), %rcx         ## 8-byte Reload
	movl	(%rcx,%rax,4), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -88(%rbp)         ## 4-byte Spill
LBB0_12:                                ##   in Loop: Header=BB0_5 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB0_5
LBB0_14:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -12(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rdi, %rsp
	movl	-12(%rbp), %ecx
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rdi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	movl	%ecx, -96(%rbp)         ## 4-byte Spill
	jne	LBB0_16
## %bb.15:
	movl	-96(%rbp), %eax         ## 4-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB0_16:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_getBit                 ## -- Begin function getBit
	.p2align	4, 0x90
_getBit:                                ## @getBit
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	cltd
	movl	$10, %ecx
	idivl	%ecx
	movl	%eax, -4(%rbp)
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	cmpl	$0, -4(%rbp)
	jne	LBB1_1
## %bb.3:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"\n"


.subsections_via_symbols
