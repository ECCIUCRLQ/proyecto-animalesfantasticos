.section .text
    .globl aprueba_colores

aprueba_colores:
    push %rbp
	mov %rsp, %rbp
	subq $18, %rsp
    vbroadcastss (%rsp), %xmm1

    mov $0, %rax
    loop:
	vmovups (%rdi, %rax), %xmm0
    add $8625, %rax
    vmovups (%rdi, %rax), %xmm1
    sub $8625, %rax
	vmovups %xmm1, (%rdi,%rax)
    add $1, %rax
	cmp %rax, %rsi
	ja loop


    mov %rbp, %rsp
	pop %rbp
	ret
