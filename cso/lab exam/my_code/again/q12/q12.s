.global q12
powerof10:
    movq $0,%r12
    movq $1,%rax

.ploop:
    cmpq %r12,%rdi
    jle .pdone

    imulq $10,%rax
    incq %r12
    jmp .ploop

.pdone:
    ret

checkprime:
    cmpq $2,%rdi
    je .creturn1
    cmpq $3,%rdi
    je .creturn1

    movq %rdi,%rax
    movq $2,%rbx
    cqto
    idivq %rbx
    movq %rax,%r13
    movq $2,%r12

.cloop:
    cmpq %r12,%r13
    jl .creturn1

    movq %rdi,%rax
    cqto
    idivq %r12
    cmpq $0,%rdx
    je .creturn0

    incq %r12
    jmp .cloop

.creturn1:
    movq $1,%rax
    ret
.creturn0:
    movq $0,%rax
    ret

q12:
    movq %rsi,%r8
    decq %r8
    movq %rdi,%r9
    movq %r8,%rdi
    call powerof10
    movq $0,%r8
    movq %rax,%r10


.mloop:
    cmpq %r8,%rsi
    jle .mdone

    movq %r9,%rdi
    call checkprime

    cmpq $1,%rax
    jne .mreturn0

    movq %r9,%rax
    cqto
    movq $10,%rbx
    idivq %rbx

    imulq %r10,%rdx
    addq %rdx,%rax
    movq %rax,%r9
    incq %r8
    jmp .mloop

.mreturn0:
    movq $0,%rax
    ret

.mdone:
    movq $1,%rax
    ret