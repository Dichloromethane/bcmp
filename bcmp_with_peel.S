.abiversion 2

// r3: char *p1
// r4: char *p2
// r5: int n
.text
.align 4
.globl bcmp_custom
bcmp_custom:
  addi %r6, %r5, 0xf
  srdi %r6, %r6, 4
  addi %r6, %r6, 1
  mtctr %r6
  and. %r6, %r5, 0xf
  sldi %r6, %r6, 56
  bdz loop_end
.align 4
loop:
  lxv %vs33, 0(%r3)
  lxv %vs34, 0(%r4)
  vcmpequb. %v3, %v2, %v1
  blt cr6, cont
  li %r3, 0
  blr
cont:
  addi %r3, %r3, 16
  addi %r4, %r4, 16
  bdnz loop
loop_end:
  lxvl %vs33, %r3, %r6
  lxvl %vs34, %r4, %r6
  vcmpequb. %v3, %v2, %v1
  blt cr6, return_true
  li %r3, 0
  blr
return_true:
  li %r3, 1
  blr
