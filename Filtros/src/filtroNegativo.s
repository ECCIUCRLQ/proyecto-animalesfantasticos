.section .text
	.globl filtro_negativo

filtro_negativo:
	push %rbp
	mov %rsp, %rbp
	subq $32, %rsp
	movl $0xffffffff, (%rsp)
	vbroadcastss (%rsp), %ymm1
	mov $0, %rax
	loop:
	vmovups (%rdi, %rax), %ymm0
	vxorps %ymm0, %ymm1, %ymm0
	vmovups %ymm0, (%rdi,%rax)
	add $32, %rax
	cmp %rax, %rsi
	ja loop
	mov %rbp, %rsp
	pop %rbp
	ret