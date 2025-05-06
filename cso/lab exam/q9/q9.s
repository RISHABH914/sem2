.section .text
.global q9

q9:
    cmpq %rdx,%rcx
    jl .returnminus

    movq %rdx,%r12
    addq %rcx,%r12
    movq %r12,%rax
    cqto
    movq $2,%rbx
    idivq %rbx

    cmpq (%rsi,%rax,8),%rdi
    je .found

    jl .gotoleft

    jmp .gotoright

.gotoleft:
    decq %rax
    movq %rax,%rcx
    call q9
    ret

.gotoright:
    incq %rax
    movq %rax,%rdx
    call q9
    ret

.found:
    ret

.returnminus:
    movq $-1,%rax
    ret


