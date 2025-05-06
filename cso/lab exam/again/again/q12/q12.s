.global q12

checkprime:
    cmpq $2,%rdi
    je .return1

    cmpq $3,%rdi
    je .return1
    movq %rdi,%r13
    movq $2,%r12
    movq %rdi,%rax
    cqto
    movq $2,%rbx
    idivq %rbx
    movq %rax,%rdi
.cloop:
    cmpq %r12,%rdi
    jle .creturn1

    movq %r13,%rax
    movq %r12,%rbx
    cqto
    idivq %rbx
    cmpq $0,%rdx
    je .creturn0

    incq %r12
    jmp .cloop

.creturn0:
    movq $0,%rax
    ret

.creturn1:
    movq $1,%rax
    ret

powerof10:
    movq $1,%rax
    movq $0,%r12

.ploop: 
    cmpq %r12,%rdi
    jle .pdone

    imulq $10,%rax
    incq %r12
    jmp .ploop
.pdone:
    ret

q12:
    movq %rdi,%r8
    movq %rsi,%r9
    decq %r9
    movq %r9,%rdi
    call powerof10

    movq %rax,%r10

    movq $0,%r11

.mllop:
    cmpq %r11,%rsi
    jle .return1

    movq %r8,%rdi
    call checkprime

    cmpq $0,%rax
    je .return0

    movq %r8,%rax
    cqto
    movq $10,%rbx
    idivq %rbx

    imulq %r10,%rdx
    addq %rdx,%rax
    movq %rax,%r8
    incq %r11
    jmp .mllop

.return0:
    movq $0,%rax
    ret
.return1:
    movq $1,%rax
    ret