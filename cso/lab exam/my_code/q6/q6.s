.global q6

q6:
    movq $0,%r8
    movq %rdi,%r12

.outerloop:
    cmpq %r8,%rdi
    jle .sortingdone

    movq $0,%r9
    decq %r12
.innerloop:
    cmpq %r9,%r12
    jle .innerdone

    movq %r9,%r10
    incq %r10

    movq (%rsi,%r9,8),%r11
    cmpq %r11,(%rsi,%r10,8)
    jl .swap

    incq %r9
    jmp .innerloop

.swap:
    movq (%rsi,%r10,8),%r13
    movq %r13,(%rsi,%r9,8)
    movq %r11,(%rsi,%r10,8);
    incq %r9
    jmp .innerloop

.innerdone:
    incq %r8
    jmp .outerloop

.sortingdone:
    movq $0,%r8
    movq %rdi,%r9
    decq %r9

.checkloop:
    cmpq %r8,%r9
    jle .return1

    movq %r8,%r10
    incq %r10
    movq (%rsi,%r8,8),%r11
    incq %r11
    cmpq %r11,(%rsi,%r10,8)
    jne .return0

    incq %r8
    jmp .checkloop

.return0:
    movq $0,%rax
    ret

.return1:
    movq $1,%rax
    ret
