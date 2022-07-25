.section .text
    .globl filtro_negativo
		.globl filtro_difuminar
		.globl filtro_espejo



filtro_negativo:
	push %rbp
	mov %rsp, %rbp
	subq $4, %rsp
	movl $0xffffffff, (%rsp)
	vbroadcastss (%rsp), %ymm1
	mov $0, %rax

	loop1:
	vmovups (%rdi, %rax), %ymm0
	vxorps %ymm0, %ymm1, %ymm0
	vmovups %ymm0, (%rdi,%rax)
	add $32, %rax
	cmp %rax, %rsi
	ja loop1

	mov %rbp, %rsp
	pop %rbp
	ret



filtro_difuminar:
    push %rbp
    mov %rsp, %rbp
    mov $0, %rax
    loop2:
    vmovups (%rdi, %rax), %xmm0
    add $32, %rax
    vmovups (%rdi, %rax), %xmm1
    sub $18, %rax
    vmovups %xmm1, (%rdi,%rax)
    add $32, %rax
    cmp %rax, %rsi
    ja loop2


    mov %rbp, %rsp
    pop %rbp
    ret


filtro_espejo:
    push %rbp
	mov %rsp, %rbp
	subq $18, %rsp

    mov $0, %rax
    loop3:
	vmovups (%rdi, %rax), %xmm0
    add $8625, %rax
    vmovups (%rdi, %rax), %xmm1
    sub $8625, %rax
	vmovups %xmm1, (%rdi,%rax)
    add $1, %rax
	cmp %rax, %rsi
	ja loop3

    mov %rbp, %rsp
	pop %rbp
		ret
