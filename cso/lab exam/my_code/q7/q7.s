.section .text
.global q7

factorial:
     movq $1,%r12
     movq %rdi,%r13
    cmpq $0,%rdi
    je .return1

    cmpq $1,%rdi
    je .return1

.loop:
    cmpq $1,%r13
    jle .give

    imulq %r13,%r12
    decq %r13
    jmp .loop

.give:
    movq %r12,%rax
    ret

.return1:
    movq $1,%rax
    ret


q7:
    movq %rdi,%r8
    movq %rdi,%r10
    movq $10,%rbx
    movq $0,%r9

.mainloop:
    cmpq $0,%r8
    jle .done

    movq %r8,%rax
    cqto
    idivq %rbx
    movq %rax,%r8

    movq %rdx,%rdi
    call factorial

    addq %rax,%r9
    jmp .mainloop

.done:
    cmpq %r9,%r10
    je .return1

    movq $0,%rax
    ret



