.section .text
    .globl filtro_difuminar

filtro_difuminar:
    push %rbp
	mov %rsp, %rbp
	subq $18, %rsp
    vbroadcastss (%rsp), %xmm1
    mov $0, %rax
    loop:
	vmovups (%rdi, %rax), %xmm0
    add $32, %rax
    vmovups (%rdi, %rax), %xmm1
    sub $18, %rax
	vmovups %xmm1, (%rdi,%rax)
    add $32, %rax
	cmp %rax, %rsi
	ja loop


    mov %rbp, %rsp
	pop %rbp
	ret
