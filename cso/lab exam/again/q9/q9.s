.global q9

q9:
    cmpq %rdx,%rcx
    jl .returnminus

    movq %rdx,%rax
    movq %rdx,%r10
    addq %rcx,%rax
    cqto
    movq $2,%rbx
    idivq %rbx

    cmpq (%rdi,%rax,8),%rsi
    je .found

    jl .gotoleft

.gotoright:
    incq %rax
    movq %rax,%rdx
    call q9
    ret

.gotoleft:
    decq %rax
    movq %r10,%rdx
    movq %rax,%rcx
    call q9
    ret

.found:
    ret
.returnminus:   
    movq $-1,%rax
    ret