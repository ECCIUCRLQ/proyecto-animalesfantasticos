.section .text
    .globl filtro_negativo
    .globl filtro_byn
    .globl filtro_sepia
    .globl filtro_borroso


filtro_negativo:
  mov $0, %rax
  jmp condition1
  loop1:
  xorb $0xff, (%rdi, %rax)
  inc %rax
  condition1:
  cmp %rsi, %rax
  jb loop1
  ret



filtro_byn:
  mov $0, %rax
  jmp condition2
  loop2:
  mov (%rdi, %rax), %cx
  shr $10, %cx
  mov %cx, %bx
  shl $5, %cx
  or %cx, %bx
  shl $5, %cx
  or %cx, %bx
  mov %bx, (%rdi, %rax)
  add $2, %rax
  condition2:
  cmp %rsi, %rax
  jb loop2
  ret


filtro_sepia:
  mov $0, %rax
  jmp condition3
  loop3:
  mov (%rdi, %rax), %cx
  mov %cx, %dx
  and $0x3e0, %dx
  cmp $0x3a0, %dx
  jb add_green
  or $0x3e0, %cx
  jmp red
  add_green:
  add $0x20, %cx
  red:
  mov %cx, %dx
  and $0x7c00, %dx
  cmp $0x6000, %dx
  jb add_red
  or $0x7c00, %cx
  jmp blue
  add_red:
  add $0x1800, %cx
  blue:
  mov %cx, %dx
  and $0x1f, %dx
  cmp $0x7, %dx
  ja sub_blue
  and $0xffe0, %cx
  jmp end
  sub_blue:
  sub $0x7, %cx
  end:
  mov %cx, (%rdi, %rax)
  add $2, %rax
  condition3:
  cmp %rsi, %rax
  jb loop3
  ret

filtro_borroso:
  mov $0, %rax
  dec %rsi
  mov $0, %dx
  mov (%rdi), %dx
  mov (%rdi), %r8w
  jmp condition4
  loop4:
  mov $0, %r11w
  mov %dx, %r9w
  mov %r9w, %r10w
  and $0x7c00, %r10w
  mov %r8w, %dx
  mov %dx, %bx
  and $0x7c00, %bx
  mov 2(%rdi, %rax), %r8w
  mov %r8w, %cx
  and $0x7c00, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  and $0x7c00, %bx
  or %bx, %r11w

  mov %r9w, %r10w
  and $0x3e0, %r10w
  mov %dx, %bx
  and $0x3e0, %bx
  mov %r8w, %cx
  and $0x3e0, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  and $0x3e0, %bx
  or %bx, %r11w

  mov %r9w, %r10w
  and $0x1f, %r10w
  mov %dx, %bx
  and $0x1f, %bx
  mov %r8w, %cx
  and $0x1f, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  or %bx, %r11w

  mov %r11w, (%rdi, %rax)

  add $2, %rax
  condition4:
  cmp %rsi, %rax
  jb loop4

  mov $0, %r11w
  mov %dx, %r9w
  mov %r9w, %r10w
  and $0x7c00, %r10w
  mov %r8w, %dx
  mov %dx, %bx
  and $0x7c00, %bx
  mov %r8w, %cx
  and $0x7c00, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  and $0x7c00, %bx
  or %bx, %r11w

  mov %r9w, %r10w
  and $0x3e0, %r10w
  mov %dx, %bx
  and $0x3e0, %bx
  mov %r8w, %cx
  and $0x3e0, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  and $0x3e0, %bx
  or %bx, %r11w

  mov %r9w, %r10w
  and $0x1f, %r10w
  mov %dx, %bx
  and $0x1f, %bx
  mov %r8w, %cx
  and $0x1f, %cx
  add %cx, %bx
  shr $1, %bx
  add %r10w, %bx
  shr $1, %bx
  or %bx, %r11w

  mov %r11w, (%rdi, %rax)

  ret
