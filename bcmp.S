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
  mtctr %r6
  li %r7, 0x0f
  and %r6, %r5, %r7
  sldi %r6, %r6, 56
  li %r8, 0x10
  sldi %r8, %r8, 56
.align 4
loop:
  cmpdi %r5, 0x10
  isellt %r7, %r6, %r8
  lxvl %vs33, %r3, %r7
  lxvl %vs34, %r4, %r7
  vcmpequb. %v3, %v2, %v1
  blt cr6, cont
  li %r3, 0
  blr
cont:
  subi %r5, %r5, 16
  addi %r3, %r3, 16
  addi %r4, %r4, 16
  bdnz loop
  li %r3, 1
  blr
