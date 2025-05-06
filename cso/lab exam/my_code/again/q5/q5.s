.global q5

q5:
    movq (%rsi),%r8
    movq %r8,(%rdx)
    movq %r8,%r10
    movq $1,%r8
    movq $1,%r9

.loop:
    cmpq %r8,%rdi
    jle .done

    cmpq (%rsi,%r8,8),%r10
    jne .newfound

    incq %r8
    jmp .loop

.newfound:
    movq (%rsi,%r8,8),%r10
    movq %r10,(%rdx,%r9,8)
    incq %r9
    incq %r8

    jmp .loop

.done:
    movq %r9,%rax
    ret