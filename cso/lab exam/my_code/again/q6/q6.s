.global q6

q6:
    movq $0,%r8
    movq %rdi,%r9
    decq %r9

.outerloop:
    cmpq %r8,%rdi
    jle .outerdone

    movq $0,%r10

.innerloop:
    cmpq %r10,%r9
    jle .innerdone

    movq %r10,%r11
    incq %r11
    movq (%rsi,%r11,8),%r12
    cmpq %r12,(%rsi,%r10,8)
    jg .swap

    incq %r10
    jmp .innerloop

.swap:
    movq (%rsi,%r10,8),%r13
    movq %r13,(%rsi,%r11,8)
    movq %r12,(%rsi,%r10,8)
    incq %r10
    jmp .innerloop

.innerdone:
    incq %r8
    jmp .outerloop

.outerdone:
    movq $0,%r8
    movq %rdi,%r9
    decq %r9

.another:
    cmpq %r8,%r9
    jle .return1

    movq (%rsi,%r8,8),%r11
    movq %r8,%r10
    incq %r10
    incq %r11
    cmpq %r11,(%rsi,%r10,8)
    jne .return0

    incq %r8
    jmp .another

.return0:
    movq $0,%rax
    ret

.return1:
    movq $1,%rax
    ret