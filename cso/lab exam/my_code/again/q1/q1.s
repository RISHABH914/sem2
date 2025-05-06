.global q1

q1:
    movq $0,%r8
    movq $1,%r9

.loop:
    cmpq %r8,%rdi
    jle .done

    movq %r9,%rax
    cqto
    movq $2,%rbx
    idivq %rbx

    cmpq $0,%rdx
    je .divby2

    movq $7,%rbx
    movq %r9,%rax
    cqto
    idivq %rbx
    cmpq $0,%rdx
    je .give2

    movq %r9,(%rsi,%r8,8);
    incq %r8
    incq %r9
    jmp .loop

.divby2:
    movq %r9,%rax
    movq $7,%rbx
    cqto
    idivq %rbx
    cmpq $0,%rdx
    je .return3

    movq $-1,(%rsi,%r8,8);
    incq %r8
    incq %r9
    jmp .loop

.return3:
    movq $-3,(%rsi,%r8,8)
    incq %r8
    incq %r9
    jmp .loop

.give2:
    movq $-2,(%rsi,%r8,8)
    incq %r8
    incq %r9
    jmp .loop

.done:
    ret