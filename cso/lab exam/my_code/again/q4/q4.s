.global q4

q4: 
    movq $0,%r8
    movq $0,%r10
.loop:
    cmpq %r8,%rdi
    jle .done

    movq (%rsi,%r8,8),%rax
    movq $3,%rbx
    cqto
    idivq %rbx

    cmpq $0,%rdx
    jne .continue

    movq (%rsi,%r8,8),%rax
    movq $5,%rbx
    cqto
    idivq %rbx

    cmpq $0,%rdx
    je .continue

    addq (%rsi,%r8,8),%r10
    incq %r8
    jmp .loop

.continue:
    incq %r8
    jmp .loop

.done:  
    movq %r10,%rax
    ret