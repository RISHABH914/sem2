.section .text
.global q4

q4:
    movq $0,%r8
    movq $0,%r9

.loop:
    cmpq %r8,%rdi
    jle .done

    movq (%rsi,%r8,8),%rax
    cqto
    movq $3,%rbx
    idivq %rbx

    cmpq $0,%rdx
    je .checkfor5

    jmp .increment

.checkfor5:
    movq $5,%rbx
    movq (%rsi,%r8,8),%rax
    cqto
    idivq %rbx

    cmpq $0,%rdx
    jne .found

    jmp .increment

.found:
    addq (%rsi,%r8,8),%r9
    jmp .increment

.increment:
    incq %r8
    jmp .loop

.done:
    movq %r9,%rax
    ret



