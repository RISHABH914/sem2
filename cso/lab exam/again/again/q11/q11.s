.global q11

q11:
    cmpq %rsi,%rdx
    jl .returnminus

    movq %rsi,%r12
    addq %rdx,%r12
    movq %rdx,%r13
    movq %r12,%rax
    cqto
    movq $2,%rbx
    idivq %rbx
    movq %rax,%r8
    movq %r13,%rdx

    cmpq (%rdi,%r8,8),%rcx
    je .found

    jg .gotoright

    decq %r8
    movq %r8,%rdx
    call q11
    ret

.gotoright:
    incq %r8
    movq %r8,%rsi
    call q11
    ret
.found:
    movq %r8,%rax
    ret
.returnminus:
    movq $-1,%rax
    ret
