.abiversion 2

// r3: char *p1
// r4: char *p2
// r5: int n
.text
.align 4
.globl bcmp_custom
bcmp_custom:
  srdi %r6, %r5, 5
  addi %r6, %r6, 2
  mtctr %r6
  and. %r6, %r5, 0x1f
  bdz loop_end
.align 4
loop:
  lxv %vs33, 0(%r3)
  lxv %vs34, 0(%r4)
  vcmpequb. %v3, %v2, %v1
  blt cr6, cont
b return_false
cont:
  lxv %vs33, 0x10(%r3)
  lxv %vs34, 0x10(%r4)
  vcmpequb. %v3, %v2, %v1
  blt cr6, cont2
  b return_false
cont2:
  addi %r3, %r3, 0x20
  addi %r4, %r4, 0x20
  bdnz loop
loop_end:
  sldi %r7, %r6, 56
  lxvl %vs33, %r3, %r7
  lxvl %vs34, %r4, %r7
  vcmpequb. %v3, %v2, %v1
  blt cr6, cont3
  b return_false
cont3:
  subi %r6, %r6, 16
  cmpdi %r6, 0
  blt return_true
  sldi %r7, %r6, 56
  lxvl %vs33, %r3, %r7
  lxvl %vs34, %r4, %r7
  vcmpequb. %v3, %v2, %v1
  blt cr6, return_true
return_false:
  li %r3, 0
  blr
return_true:
  li %r3, 1
  blr
