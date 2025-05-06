.global q2

q2:
    movq %rdi,%r8
    movq $0,%r9
.loop:  
    cmpq $0,%r8
    je .check

    movq %r8,%rax
    movq $10,%rbx
    cqto
    idivq %rbx
    movq %rdx,(%rsi,%r9,8)
    movq %rax,%r8
    incq %r9
    jmp .loop

.check:
    decq %r9

.another:
    cmpq $0,%r9
    jl .return1

    movq %rdi,%rax
    cqto
    movq $10,%rbx
    idivq %rbx

    cmpq %rdx,(%rsi,%r9,8)
    jne .return0

    movq %rax,%rdi
    decq %r9
    jmp .another

.return0:
    movq $0,%rax
    ret
.return1:
    movq $1,%rax
    ret
