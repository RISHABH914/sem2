.section .text
.global q3

q3:
    incq %rdi
    movq $0,%r8
.loop:
    movzbq (%rdi),%rax
    cmpb $0,%al
    je .done

    movzbq -1(%rdi),%rax
    movzbq (%rdi),%rbx
    subq %rax,%rbx
    cmpq $0,%rbx
    jl .negate

    addq %rbx,%r8
    jmp .increment

.negate:
    negq %rbx
    addq %rbx,%r8
    jmp .increment

.increment:
    incq %rdi
    jmp .loop

.done:
    movq %r8,%rax
    ret





