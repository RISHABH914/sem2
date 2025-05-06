.global q7

factorial:
    cmpq $0,%rdi
    je .freturn1
    movq $1,%rax

.floop:
    cmpq $1,%rdi
    jle .return

    imulq %rdi,%rax
    decq %rdi
    jmp .floop

.freturn1:
    movq $1,%rax
    ret
.return:
    ret

q7:
    movq $0,%r9
    movq %rdi,%r10

.loop:
    cmpq $0,%rdi
    jle .done

    movq %rdi,%rax
    cqto
    movq $10,%rbx
    idivq %rbx
    movq %rdx,%rdi
    movq %rax,%r8
    call factorial

    addq %rax,%r9
    movq %r8,%rdi
    jmp .loop

.done:
    cmpq %r9,%r10
    je .true

    movq $0,%rax
    ret

.true:  
    movq $1,%rax
    ret


