	.file	"a.c"
	.text
	.section .rdata,"dr"
LC0:
	.ascii "123\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$LC0, (%esp)
	call	___mingw_printf
	movl	$0, %eax
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.2.0"
