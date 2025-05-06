.section .text
.global q2

findlength:
    movq $0,%r12
    movq %rdi,%r13

.floop:
    cmpq $0,%r13
    jle .return

    movq %r13,%rax
    cqto
    movq $10,%rbx
    idivq %rbx
    movq %rax,%r13
    incq %r12
    jmp .floop

.return:
    movq %r12,%rax
    ret

q2:
    movq %rdi,%r8
    call findlength

    movq %rax,%r9
    movq %r9,%r11
    movq $0,%r10

.loop:
    cmpq %r10,%r11
    jle .done

    movq %r8,%rax
    cqto
    movq $10,%rbx
    idivq %rbx
    movq %rdx,(%rsi,%r10,8)
    movq %rax,%r8
    incq %r10
    jmp .loop

.done:
    decq %r11
    movq $0,%r10

.anotherloop:
    cmpq %r10,%r9
    jle .finaldone

    movq %rdi,%rax
    cqto
    movq $10,%rbx
    idivq %rbx

    cmpq %rdx,(%rsi,%r11,8);
    jne .return0

    movq %rax,%rdi
    decq %r11
    incq %r10
    jmp .anotherloop

.finaldone:
    movq $1,%rax
    ret
.return0:
    movq $0,%rax
    ret