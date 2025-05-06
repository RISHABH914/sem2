.global q3

q3: 
    movzbq (%rdi),%r9
    incq %rdi
    movq $0,%r10
.loop:
    movzbq (%rdi),%r8
    cmpq $0,%r8
    je .done

    movq %r8,%r11
    subq %r9,%r8
    movq %r11,%r9

    cmpq $0,%r8
    jl .negate

    addq %r8,%r10
    incq %rdi
    jmp .loop

.negate:    
    negq %r8
    addq %r8,%r10
    incq %rdi
    jmp .loop

.done:
    movq %r10,%rax
    ret

